#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 250000;
const int BLOCK = 500;
const ll INF = 1e18;

ll arr [MAX_N];
ll block_add [BLOCK];
int smallest [BLOCK];

void refresh_smallest (int block_id) {
  pair<ll, int> ans = make_pair(arr[block_id * BLOCK], - block_id * BLOCK);
  for (int i = block_id * BLOCK; i < (block_id + 1) * BLOCK; i++) {
    ans = min(ans, make_pair(arr[i], -i));
  }
  smallest[block_id] = -ans.second;
}

void subtract_suffix (int start, ll val) {
  int to_upd = -1;
  while (start % BLOCK != 0) {
    arr[start] -= val;
    to_upd = start / BLOCK;
    start++;
  }

  if (to_upd != -1) {
    refresh_smallest(to_upd);
  }

  for (int i = start / BLOCK; i < BLOCK; i++) {
    block_add[i] -= val;
  }
}

void make_inf (int idx) {
  arr[idx] = INF;
  refresh_smallest(idx / BLOCK);
}

ll get_value (int idx) {
  return block_add[idx / BLOCK] + arr[idx];
}

int rightmost_zero () {
  int ans = -1;
  for (int i = 0; i < BLOCK; i++) {
    if (get_value(smallest[i]) == 0) {
      ans = smallest[i];
    }
  }
  return ans;
}

int ans [MAX_N];

int main () {
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }
  for (int i = length; i < MAX_N; i++) {
    arr[i] = INF;
  }

  for (int i = 0; i < BLOCK; i++) {
    refresh_smallest(i);
  }
  
  for (int i = 1; i <= length; i++) {
    int pos = rightmost_zero();
    make_inf(pos);
    subtract_suffix(pos, i);
    ans[pos] = i;
  }

  for (int i = 0; i < length; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}