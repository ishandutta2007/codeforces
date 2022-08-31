#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 3e5 + 5;
const int BLOCK = 800;
const int MOD = 1e9 + 9;

typedef long long ll;

int fib [MAX_N];
int cumfib [MAX_N];
ll cum [MAX_N];

vector<pair<int, int>> buf;
ll pls [MAX_N];
ll cur [MAX_N];
void rebuild () {
  for (int i = 0; i < MAX_N; i++) {
    pls[i] = 0;
  }

  for (pair<int, int> pr : buf) {
    int len = pr.second - pr.first + 1;
    pls[pr.first] += 1;
    pls[pr.second + 1] += MOD - fib[len] + MOD - fib[len - 1];
    pls[pr.second + 2] += MOD - fib[len];
  }
  buf.clear();

  cur[1] = cur[0] + pls[1];
  for (int i = 2; i < MAX_N; i++) {
    cur[i] = (cur[i - 1] + cur[i - 2] + pls[i]) % MOD;
  }

  for (int i = 1; i < MAX_N; i++) {
    cur[i] += cur[i - 1];
    cur[i] %= MOD;
  }

  for (int i = 0; i < MAX_N; i++) {
    cum[i] += cur[i];
    cum[i] %= MOD;
  }
}

void add (int l, int r) {
  if ((int) buf.size() > BLOCK) {
    rebuild();
  }
  buf.push_back({l, r});
}

int sum (int l, int r) {
  ll ans = cum[r] + MOD - cum[l - 1];
  for (auto pr : buf) {
    if (pr.second < l || r < pr.first) {
    } else if (l <= pr.first && pr.second <= r) {
      ans += cumfib[pr.second - pr.first + 1];
    } else if (l <= pr.first && r < pr.second) {
      ans += cumfib[r - pr.first + 1];
    } else if (pr.first < l && pr.second <= r) {
      ans += cumfib[pr.second - pr.first + 1] + MOD - cumfib[l - pr.first];
    } else {
      ans += cumfib[r - pr.first + 1] + MOD - cumfib[l - pr.first];
    }
  }
  return ans % MOD;
}

int main () {
  ios::sync_with_stdio(false);

  fib[1] = 1;
  fib[2] = 1;
  for (int i = 3; i < MAX_N; i++) {
    fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
  }

  for (int i = 1; i < MAX_N; i++) {
    cumfib[i] = (cumfib[i - 1] + fib[i]) % MOD;
  }

  int length, queryc;
  cin >> length >> queryc;
  for (int i = 1; i <= length; i++) {
    cin >> cum[i];
  }
  
  for (int i = 1; i <= length; i++) {
    cum[i] += cum[i - 1];
    cum[i] %= MOD;
  }

  for (int i = 0; i < queryc; i++) {
    int t, l, r;
    cin >> t >> l >> r;

    if (t == 1) {
      add(l, r);
    } else {
      cout << sum(l, r) << "\n";
    }
  }
}