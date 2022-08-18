#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
class fenwick {
  vector<int> tree;
  int length;
 
public:
  fenwick (int _length) {
    length = _length;
    tree = vector<int> (length + 1, 0);
  }
 
  int get (int idx) {
    int ans = 0;
    for (int i = idx; i != 0; i -= i & -i) {
      ans = max(ans, tree[i]);
    }
    return ans;
  }
 
  void set (int idx, int val) {
    for (int i = idx; i <= length; i += i & -i) {
      tree[i] = max(tree[i], val);
    }
  }
};
 
const int MAX_N = 100005;
 
int seg_starts [MAX_N], seg_ends [MAX_N];
int arr [MAX_N];
int dp [MAX_N], rev_dp [MAX_N];
 
int main () {
  int segc, length;
  cin >> segc >> length;
 
  for (int i = 0; i < segc; i++) {
    int l, r;
    cin >> l >> r;
 
    seg_starts[l]++;
    seg_ends[r]++;
  }
 
  int cur = 0;
  for (int i = 1; i <= length; i++) {
    cur += seg_starts[i];
    arr[i] = cur;
    cur -= seg_ends[i];
  }
 
  {
    vector<pair<int, int>> elems;
    for (int i = 1; i <= length; i++) {
      elems.push_back(make_pair(arr[i], i));
    }
 
    sort(elems.begin(), elems.end());
 
    fenwick dp_calc (length);
    for (pair<int, int> pr : elems) {
      dp[pr.second] = dp_calc.get(pr.second) + 1;
      dp_calc.set(pr.second, dp[pr.second]);
    }
  }
 
  reverse(arr + 1, arr + length + 1);
 
  {
    vector<pair<int, int>> rev_elems;
    for (int i = 1; i <= length; i++) {
      rev_elems.push_back(make_pair(arr[i], i));
    }
 
    sort(rev_elems.begin(), rev_elems.end());
 
    fenwick rev_dp_calc (length);
    for (pair<int, int> pr : rev_elems) {
      rev_dp[pr.second] = rev_dp_calc.get(pr.second) + 1;
      rev_dp_calc.set(pr.second, rev_dp[pr.second]);
    }
 
    reverse(rev_dp + 1, rev_dp + length + 1);
  }
 
  int ans = 0;
  for (int i = 1; i <= length; i++) {
    ans = max(ans, dp[i] + rev_dp[i] - 1);
  }
 
  cout << ans << endl;
}