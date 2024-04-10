#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;
struct modint {
  int val;

  modint () {
    val = 0;
  }

  modint (ll _val) {
    val = _val % MOD;
  }
};

modint operator+ (modint p, modint q) {
  return modint((p.val + q.val) % MOD);
}

modint operator- (modint p, modint q) {
  return modint((p.val - q.val + MOD) % MOD);
}

modint operator- (modint p) {
  return modint(0) - p;
}

modint operator* (modint p, modint q) {
  return modint(((ll) p.val * (ll) q.val) % MOD);
}

modint operator^ (modint p, int q) {
  modint pows [30];

  pows[0] = p;
  for (int i = 1; i < 30; i++) {
    pows[i] = pows[i - 1] * pows[i - 1];
  }

  modint ans (1);
  for (int i = 0; i < 30; i++) {
    if (q & 1 << i) {
      ans = ans * pows[i];
    }
  }

  return ans;
}

modint operator/ (modint p, modint q) {
  return p * (q ^ (MOD - 2));
}

modint inv (modint p) {
  return p ^ (MOD - 2);
}

vector<modint> evolve (vector<modint> cur) {
  int n = (int) cur.size();
  vector<modint> nxt (n, modint(0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      nxt[j] = nxt[j] + cur[i] / modint(i + 1);
    }
  }
  return nxt;
}

modint fact [10505];
modint ncr (int n, int r) {
  return fact[n] / (fact[r] * fact[n - r]);
}

modint dp [55][55][10005];

const int maxp = 32000000;

int comp [maxp];
modint invm [10005];

int main () {
  fact[0] = modint(1);
  for (int i = 1; i < 10005; i++) {
    invm[i] = modint(1) / modint(i);
  }
  
  for (int i = 2; i < maxp; i++) {
    if (comp[i] == 0) {
      for (int j = 2 * i; j < maxp; j += i) {
        comp[j] = 1;
      }
    }
  }

  ll init;
  cin >> init;

  vector<pair<ll, int>> multips;
  for (int i = 2; i < maxp; i++) {
    if (!comp[i]) {
      if (init % i == 0) {
        int cur = 0;
        while (init % i == 0) {
          init /= i;
          cur++;
        }
        multips.push_back(make_pair(i, cur));
      }
    }
  }

  if (init != 1) {
    multips.push_back(make_pair(init, 1));
  }

  int iters;
  cin >> iters;
  for (int i = 1; i < 50; i++) {
    dp[i][i][0] = 1;
    for (int k = 1; k <= iters; k++) {
      for (int j = i; j >= 0; j--) {
        dp[i][j][k] = dp[i][j + 1][k] + dp[i][j][k - 1] * invm[j + 1];
      }
    }
  }
  
  modint ans (1);
  for (pair<ll, int> pr : multips) {
    modint cur (0);
    modint prime (pr.first);
    modint pcur (1);
    for (int i = 0; i <= pr.second; i++) {
      cur = cur + dp[pr.second][i][iters] * pcur;
      pcur = pcur * prime;
    }
    ans = ans * cur;
  }
  cout << ans.val << endl;
}