#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>,
  rb_tree_tag, tree_order_statistics_node_update>;

// cur.order_of_key(2)
// the number of elements in the set less than 2
// *cur.find_by_order(1)
// the 1-st smallest number in the set(0-based)

typedef long long ll;

const int MAX_LG = 29;

// look at only k-th bits
ll count_inv (const vector<int> &arr, int k) {
  int n = arr.size();

  ll ans = 0;
  int ones = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] & 1 << k) {
      ones++;
    } else {
      ans += ones;
    }
  }
  return ans;
}

/*
ll count_inv (const vector<int> &arr, int k) {
  int n = arr.size();
  
  ll ans = 0;
  ordered_set<pair<int, int>> seen;
  for (int i = n - 1; i >= 0; i--) {
    ans += seen.order_of_key(make_pair(arr[i] >> k, -1)); // # of strictly smaller to the right
    seen.insert(make_pair(arr[i] >> k, i));
  }
  return ans;
}
*/

void flip_bit (vector<int> &arr, int bit) {
  for (auto &u : arr) {
    u ^= 1 << bit;
  }
}

int K;
bool comp (int p, int q) {
  return (p >> K) < (q >> K);
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<vector<int>> cur (1, vector<int> (n));
  for (int i = 0; i < n; i++) {
    cin >> cur[0][i];
  }

  int x = 0;
  ll invs = 0;
  for (int k = MAX_LG; k >= 0; k--) {
    ll invs_0 = 0;
    for (auto &block : cur) { 
      invs_0 += count_inv(block, k);
    }

    ll invs_1 = 0;
    for (auto &block : cur) {
      flip_bit(block, k);
      invs_1 += count_inv(block, k);
    }

    if (invs_0 <= invs_1) {
      for (auto &block : cur) {
        flip_bit(block, k);
      }
      invs += invs_0;
    } else {
      invs += invs_1;
      x |= 1 << k;
    }

    vector<vector<int>> nxt;
    for (int t = 0; t < (int) cur.size(); t++) {
      nxt.push_back(vector<int> (0));
      for (int u : cur[t]) {
        if (!(u & 1 << k)) {
          nxt.back().push_back(u);
        }
      }
      if (nxt.back().empty()) nxt.pop_back();

      nxt.push_back(vector<int> (0));
      for (int u : cur[t]) {
        if ((u & 1 << k)) {
          nxt.back().push_back(u);
        }
      }
      if (nxt.back().empty()) nxt.pop_back();      
    }
    
    cur = nxt;
  }

  cout << invs << " " << x << endl;
}