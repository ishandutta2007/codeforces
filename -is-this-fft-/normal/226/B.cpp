#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

int n;
ll arr [MAX_N];

bool seen [MAX_N];
ll memo [MAX_N];

ll solve (ll K) {
  if (seen[K]) {
    return memo[K];
  }

  ll ans = 0;
  ll len = 1, cur = 1;
  for (ll i = 0; true; i++) {
    int L = cur, R = min((ll) n, cur + len - 1);
    ans += i * (arr[R] - arr[L - 1]);

    if (R == n) {
      break;
    }
    
    cur += len;
    len *= K;
  }

  seen[K] = true;
  memo[K] = ans;
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  sort(arr + 1, arr + n + 1, greater<ll>());

  for (int i = 1; i <= n; i++) {
    arr[i] += arr[i - 1];
  }

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    int k;
    cin >> k;

    cout << solve(k) << " ";
  }
  cout << endl;
}