#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 5;

int arr [MAX_N];
int cnt [MAX_N];
int bal [MAX_N];
int ans [MAX_N];

void solve () {
  int n, K;
  cin >> n >> K;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    cnt[i] = 0;
    ans[i] = -1;
  }

  for (int i = 1; i <= n; i++) {
    cnt[arr[i]]++;
  }

  pair<int, int> best = make_pair(1, n);
  int rptr = 0, cur = 0;
  for (int lptr = 1; lptr <= n; lptr++) {
    cur -= cnt[lptr - 1];
    while (cur < K + n - cur && rptr < n) {
      rptr++;
      cur += cnt[rptr];
    }

    if (cur < K + n - cur) {
      break;
    }

    if (rptr - lptr < best.second - best.first) {
      best = make_pair(lptr, rptr);
    }
  }

  int x = best.first, y = best.second;
  for (int i = 1; i <= n; i++) {
    if (x <= arr[i] && arr[i] <= y) {
      bal[i] = bal[i - 1] + 1;
    } else {
      bal[i] = bal[i - 1] - 1;
    }

    if (1 <= bal[i] && bal[i] < K && ans[bal[i]] == -1) {
      ans[bal[i]] = i;
    }
  }
  ans[K] = n;

  cout << x << " " << y << '\n';
  for (int i = 1; i <= K; i++) {
    cout << ans[i - 1] + 1 << " " << ans[i] << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}