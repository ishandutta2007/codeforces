#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

const int maxn = 300005;

int length;
vector<pair<int, int>> ans;
int arr [maxn];
int pos [maxn];

void direct_swap (int u, int v) {
  if (u == v) return;
  assert(2 * abs(u - v) >= length); 
  
  ans.push_back(make_pair(u, v));
  swap(pos[arr[u]], pos[arr[v]]);
  swap(arr[u], arr[v]);
}

void swap_idx (int u, int v) {
  if (u == v) return;
  if (u > v) swap(u, v);

  if (u <= length / 2 && v > length / 2) {
    if (u == 1 || v == length) {
      direct_swap(u, v);
    } else {
      direct_swap(u, length);
      direct_swap(v, 1);
      direct_swap(1, length);
      direct_swap(u, length);
      direct_swap(v, 1);
    }
  } else if (u <= length / 2 && v <= length / 2) {
    direct_swap(u, length);
    direct_swap(v, length);
    direct_swap(u, length);
  } else {
    direct_swap(u, 1);
    direct_swap(v, 1);
    direct_swap(u, 1);
  }
}

int main () {
  cin >> length;

  for (int i = 1; i <= length; i++) {
    cin >> arr[i];
    pos[arr[i]] = i;
  }

  for (int i = 1; i <= length; i++) {
    swap_idx(i, pos[i]);
  }

  cout << (int) ans.size() << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << '\n';
  }
}