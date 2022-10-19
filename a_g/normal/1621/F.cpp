#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, a, b, c;
    string s;
    cin >> n >> a >> b >> c >> s;
    long long ans = 0;
    for (int z = 0; z < 2; z++) {
      int type2_op = 0;
      for (int i = 0; i < n-1; i++) {
        if (s[i] == '1' && s[i+1] == '1') type2_op++;
      }
      vector<int> middle_blocks, edge_blocks;
      int l = 0;
      while (l < n && s[l] == '1') l++;
      while (l < n) {
        int r = l;
        while (r < n && s[r] == '0') r++;
        if (l == 0 || r == n) {
          edge_blocks.emplace_back(r-l);
        }
        else {
          middle_blocks.emplace_back(r-l);
        }
        l = r;
        while (l < n && s[l] == '1') l++;
      }
      assert((int)edge_blocks.size() <= 2);

      sort(middle_blocks.begin(), middle_blocks.end());
      sort(edge_blocks.begin(), edge_blocks.end());

      int middle_sz = (int)middle_blocks.size();
      int edge_sz = (int)edge_blocks.size();
      int middle_ptr = 0; // first middle block of size at least 2
      int edge_ptr = 0; // first edge block of size at least 2
      while (middle_ptr < middle_sz
          && middle_blocks[middle_ptr] == 1) middle_ptr++;
      while (edge_ptr < edge_sz
          && edge_blocks[edge_ptr] == 1) edge_ptr++;
      int small_middle_blocks = middle_ptr;
      int small_edge_blocks = edge_ptr;

      long long cur = 0;
      int op_type = z;
      while (1) {
        if (op_type == 0) {
          if (type2_op == 0) {
            break;
          }
          cur += b;
          type2_op--;
        }
        else {
          if (type2_op == 0) {
            if (middle_ptr < middle_sz || edge_ptr < edge_sz) {
              ans = max(ans, cur+a);
            }
            if (small_middle_blocks) {
              cur -= c;
              small_middle_blocks--;
              type2_op++;
            }
            else {
              break;
            }
          }
          else {
            if (middle_ptr < middle_sz) {
              cur += a;
              middle_blocks[middle_ptr]--;
              if (middle_blocks[middle_ptr] == 1) {
                middle_ptr++;
                small_middle_blocks++;
              }
            }
            else if (edge_ptr < edge_sz) {
              cur += a;
              edge_blocks[edge_ptr]--;
              if (edge_blocks[edge_ptr] == 1) {
                edge_ptr++;
                small_edge_blocks++;
              }
            }
            else if (small_middle_blocks) {
              cur -= c;
              small_middle_blocks--;
              type2_op++;
            }
            else if (small_edge_blocks) {
              cur -= c;
              small_edge_blocks--;
            }
            else {
              break;
            }
          }
        }
        ans = max(ans, cur);
        op_type = 1-op_type;
      }
    }
    cout << ans << '\n';
  }
}