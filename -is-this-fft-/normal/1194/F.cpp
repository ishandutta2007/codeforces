#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;

struct modint {
  ll val;

  modint () {
    val = 0;
  }

  modint (ll _val) {
    val = _val;
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
  return modint((p.val * q.val) % MOD);
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

const int MAX_N = 200005;

modint fact [MAX_N];

modint choose (int n, int k) {
  return fact[n] / (fact[n - k] * fact[k]);
}

struct SumChoose {
  modint val;
  int n, k;

  SumChoose () {
    n = 1;
    k = 0;
    val = modint(1);
  }

  void addN () {
    val = modint(2) * val - choose(n, k);
    n++;
  }

  void addK () {
    k++;
    val = val + choose(n, k);
  }

  void decK () {
    val = val - choose(n, k);
    k--;
  }

  modint get (int _n, int _k) {
    while (n < _n) {
      addN();
    }

    while (k < _k) {
      addK();
    }

    while (k > _k) {
      decK();
    }

    return val;
  }
};

ll timeAt [MAX_N];
ll timeSum [MAX_N];
modint prob [MAX_N];

int main () {
  fact[0] = modint(1);
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = fact[i - 1] * modint(i);
  }
  
  ios::sync_with_stdio(false);

  ll length, queryTime;
  cin >> length >> queryTime;

  for (int i = 1; i <= length; i++) {
    cin >> timeAt[i];
  }

  timeSum[1] = timeAt[1];
  for (int i = 2; i <= length; i++) {
    timeSum[i] = timeSum[i - 1] + timeAt[i];
  }

  SumChoose sumChoose;
  for (int i = 1; i <= length; i++) {
    ll K = queryTime - timeSum[i];
    if (K < 0) {
      prob[i] = modint(0);
    } else if (K > i) {
      prob[i] = modint(1);
    } else {
      prob[i] = sumChoose.get(i, K) / (modint(2) ^ i);
    }
  }
  
  for (int i = 1; i < length; i++) {
    prob[i] = prob[i] - prob[i + 1];
  }

  /*
  for (int i = 1; i <= length; i++) {
    cout << prob[i].val << " ";
  }
  cout << '\n';
  */

  modint ans = 0;
  for (int i = 1; i <= length; i++) {
    ans = ans + modint(i) * prob[i];
  }

  cout << ans.val << '\n';
}