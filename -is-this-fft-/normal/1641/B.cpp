#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

// [0 r] inclusive
void pref_invert (int r, deque<int> &arr,
                  vector<pair<int, int>> &ops, vector<int> &ans, int &add) {
  vector<int> slice (arr.begin(), arr.begin() + r + 1);
  for (int i = 0; i < (int) slice.size(); i++) {
    ops.emplace_back(slice[i], add + r + 1 + i);
  }

  ans.push_back(2 * (r + 1));
  add += 2 * (r + 1);

  reverse(arr.begin(), arr.begin() + r + 1);
}

void solve () {
  int n;
  cin >> n;

  map<int, int> cnt;
  deque<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
  }

  for (auto pr : cnt) {
    if (pr.second % 2 == 1) {
      cout << -1 << '\n';
      return;
    }
  }

  vector<int> ans;
  vector<pair<int, int>> ops;
  int add = 0;
  while (!arr.empty()) {
    // find the first repeat
    map<int, int> cur_cnt;
    int rep_pos = 0;
    for (int i = 0; true; i++) {
      cur_cnt[arr[i]]++;
      if (cur_cnt[arr[i]] == 2) {
        rep_pos = i;
        break;
      }
    }

    // find its first position
    int fst_pos = 0;
    for (int i = 0; true; i++) {
      if (arr[i] == arr[rep_pos]) {
        fst_pos = i;
        break;
      }
    }

    // perform a prefix inversion
    pref_invert(fst_pos, arr, ops, ans, add);

    // then work the magic
    vector<int> slice (arr.begin() + 1, arr.begin() + rep_pos);
    for (int i = 0; i < (int) slice.size(); i++) {
      ops.emplace_back(slice[i], add + rep_pos + 1 + i);
    }

    ans.push_back(2 * rep_pos);
    add += 2 * rep_pos;
    for (int i = 0; i <= rep_pos; i++) {
      arr.pop_front();
    }

    reverse(slice.begin(), slice.end());
    arr.insert(arr.begin(), slice.begin(), slice.end());
  }

  cout << (int) ops.size() << '\n';
  for (auto op : ops) {
    cout << op.second << " " << op.first << '\n';
  }

  cout << (int) ans.size() << '\n';
  for (auto t : ans) {
    cout << t << " ";
  }
  cout << '\n';
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