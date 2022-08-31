#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

int cur [MAX_N];

void solve () {
  int n, L, R;
  cin >> n >> L >> R;

  for (int i = 1; i <= n; i++) {
    cur[i] = 0;
  }
  
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (i < L) {
      cur[x]--;
    } else {
      cur[x]++;
    }
  }

  vector<int> neg_odd, pos_odd;
  for (int i = 1; i <= n; i++) {
    if (cur[i] % 2 != 0) {
      if (cur[i] < 0) {
        neg_odd.push_back(i);
      } else {
        pos_odd.push_back(i);
      }
    }
  }

  int ans = 0;
  while (!neg_odd.empty() && !pos_odd.empty()) {
    int neg = neg_odd.back();
    neg_odd.pop_back();
    int pos = pos_odd.back();
    pos_odd.pop_back();

    cur[neg]++;
    cur[pos]--;
    ans++;
  }

  if (!pos_odd.empty()) {
    swap(pos_odd, neg_odd);
    for (int i = 1; i <= n; i++) {
      cur[i] = -cur[i];
    }
  }

  vector<int> pos_ev;
  for (int i = 1; i <= n; i++) {
    if (cur[i] > 0 && cur[i] % 2 == 0) {
      for (int j = 0; j < cur[i]; j++) {
        pos_ev.push_back(i);
      }
    }
  }

  while (!neg_odd.empty() && !pos_ev.empty()) {
    int u = neg_odd.back();
    neg_odd.pop_back();
    int v = neg_odd.back();
    neg_odd.pop_back();

    int a = pos_ev.back();
    pos_ev.pop_back();
    int b = pos_ev.back();
    pos_ev.pop_back();

    cur[u]++;
    cur[v]++;
    cur[a]--;
    cur[b]--;
    ans += 2;
  }
  
  while (!neg_odd.empty()) {
    int u = neg_odd.back();
    neg_odd.pop_back();
    int v = neg_odd.back();
    neg_odd.pop_back();

    cur[u]++;
    cur[v]--;
    ans++;
  }

  for (int i = 1; i <= n; i++) {
    ans += abs(cur[i]) / 2;
  }

  cout << ans << '\n';
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