#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 500015;

int nxt [maxn];
int arr [maxn];
pair<int, int> depth [maxn];
vector<int> events [maxn];

void solve () {
  int length;
  cin >> length;

  for (int i = 0; i < length + 5; i++) {
    nxt[i] = 0;
    arr[i] = 0;
    depth[i] = make_pair(0, 0);
    events[i].clear();
  }

  for (int i = 1; i <= length; i++) {
    cin >> nxt[i];
  }

  vector<int> cur_stk;
  for (int i = 1; i <= length; i++) {
    while (!events[i].empty()) {
      if (events[i].back() != cur_stk.back()) {
        cout << -1 << '\n';
        return;
      }
      events[i].pop_back();
      cur_stk.pop_back();
    }

    depth[i] = make_pair(-(int) cur_stk.size(), i);
    
    if (nxt[i] != -1) {
      events[nxt[i]].push_back(i);
      cur_stk.push_back(i);
    }
  }

  sort(depth + 1, depth + length + 1);
  for (int i = 1; i <= length; i++) {
    arr[depth[i].second] = i;
  }

  for (int i = 1; i <= length; i++) {
    cout << arr[i] << " ";
  }
  cout << '\n';
}
  

int main () {
  ios::sync_with_stdio(false);
  
  int testc;
  cin >> testc;
  for (int i = 0; i < testc; i++) {
    solve();
  }
}