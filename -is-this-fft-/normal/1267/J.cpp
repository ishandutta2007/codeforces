#include <iostream>

using namespace std;

const int MAX_N = 2e6 + 5;

int arr [MAX_N];
int cnt [MAX_N];
int legal [MAX_N];

int ceil (int u, int v) {
  return (u + v - 1) / v;
}

void solve () {
  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cnt[i] = 0;
  }

  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
  }

  int mins = MAX_N;
  for (int i = 1; i <= N; i++) {
    if (cnt[i] > 0) {
      mins = min(mins, cnt[i] + 1);
    }
  }

  for (int i = 1; i <= mins; i++) {
    legal[i] = 1;
  }

  for (int i = 1; i <= N; i++) {
    if (cnt[i] > 0) {
      for (int s = 1; s <= mins; s++) {
        int screenc = ceil(cnt[i], s);
        if (screenc * (s - 1) > cnt[i]) {
          legal[s] = 0;
        }
      }
    }
  }

  for (int i = mins; i >= 1; i--) {
    if (legal[i]) {
      int ans = 0;
      for (int k = 1; k <= N; k++) {
        ans += ceil(cnt[k], i);
      }
      cout << ans << '\n';
      return;
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}