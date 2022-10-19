#include <bits/stdc++.h>
using namespace std;

struct node {
  shared_ptr<node> children[2] = {nullptr, nullptr};
  int bit, mx[2][2] = {{0, 0}, {0, 0}};
  node (int b): bit(b) { }
  int qry(int x, int i) {
    // x = a[i]^i
    int xb = (x>>bit)&1;
    int k = mx[1-xb][(i>>bit)&1];
    if (bit == 0) return k;
    if (children[xb] == nullptr) {
      children[xb] = shared_ptr<node>(new node(bit-1));
    }
    return max(k, children[xb]->qry(x, i));
  }
  void place(int x, int a, int val) {
    int ab = (a>>bit)&1;
    int xb = (x>>bit)&1;
    mx[xb][ab] = max(mx[xb][ab], val);
    if (bit == 0) return;
    if (children[xb] == nullptr) {
      children[xb] = shared_ptr<node>(new node(bit-1));
    }
    children[xb]->place(x, a, val);
  }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), dp(n, 1);
    for (int& x: a) cin >> x;
    node trie(30);
    for (int i = 0; i < n; i++) {
      dp[i] = trie.qry(a[i]^i, i)+1;
      trie.place(a[i]^i, a[i], dp[i]);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
}