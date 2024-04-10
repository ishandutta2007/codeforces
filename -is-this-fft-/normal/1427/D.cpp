#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;


// returns the operation needed
// or empty vector is arr is sorted
vector<int> find_op (const vector<int> &arr) {
  int n = arr.size();
  vector<int> pos (n);
  for (int i = 0; i < n; i++) {
    pos[arr[i]] = i;
  }

  int to_swap = -1;
  for (int i = 0; i < n - 1; i++) {
    if (pos[i] > pos[i + 1]) {
      to_swap = i;
    }
  }

  if (to_swap == -1) {
    return vector<int> (0);
  }

  int i = to_swap;
  deque<int> ans = {pos[i + 1], pos[i] - pos[i + 1], 1, n - pos[i] - 1};
  for (int j = 1; true; j++) {
    if (arr[pos[i] - j] == i - j) {
      ans[1]--;
      ans[2]++;
    } else {
      break;
    }
  }
  
  if (ans.back() == 0) {
    ans.pop_back();
  }
  if (ans[0] == 0) {
    ans.pop_front();
  }
  return vector<int> (ans.begin(), ans.end());
}

vector<int> operate (const vector<int> &arr, const vector<int> &op) {
  vector<vector<int>> blocks;
  int ptr = 0;
  for (int i = 0; i < (int) op.size(); i++) {
    blocks.push_back(vector<int> (0));
    for (int j = ptr; j < ptr + op[i]; j++) {
      blocks.back().push_back(arr[j]);
    }
    ptr += op[i];
  }

  reverse(blocks.begin(), blocks.end());
  
  vector<int> ans;
  for (auto &v : blocks) {
    for (auto u : v) {
      ans.push_back(u);
    }
  }
  return ans;
}

int main () {
  int n;
  cin >> n;

  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i]--;
  }

  vector<vector<int>> ops;
  while (true) {
    auto op = find_op(arr);
    if (op.empty()) break;
    arr = operate(arr, op);
    ops.push_back(op);
  }
  cout << (int) ops.size() << '\n';
  for (auto &op : ops) {
    cout << (int) op.size();
    for (int d : op) {
      cout << " " << d;
    }
    cout << '\n';
  }
}