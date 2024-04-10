#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 50;
const int mod = 1e9 + 7;
const int M = 1e6 + 10;
vector <int> seg[4 * maxn], v[maxn];
map <int, int> s[maxn];

void build (int id, int L, int R){
  if (L + 1 == R){
    seg[id] = v[L];
    sort (seg[id].begin(), seg[id].end());
	return;
  }
  int mid = (L + R) / 2;
  build (2 * id + 0, L, mid);
  build (2 * id + 1, mid, R);
  int idx1 = 0, idx2 = 0;
  for (auto i : seg[2 * id + 0])
    seg[id].PB (i);
  for (auto i : seg[2 * id + 1])
    seg[id].PB (i);
  sort (seg[id].begin(), seg[id].end());
  return;
}

ll get (int id, int L, int R, int l, int r, int minval, int maxval){
  if (L == l and R == r){
    int idx1 = lower_bound (seg[id].begin(), seg[id].end(), minval) - seg[id].begin();
    int idx2 = lower_bound (seg[id].begin(), seg[id].end(), maxval) - seg[id].begin();
	return idx2 - idx1;
  }
  int mid = (L + R) / 2;
  ll ret = 0;
  if (mid > l)
    ret += get (2 * id + 0, L, mid, l, min (mid, r), minval, maxval);
  if (mid < r)
    ret += get (2 * id + 1, mid, R, max (l, mid), r, minval, maxval);
  return ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++){
    int l, r;
    cin >> l >> r;
    v[l].PB (r);
  }
  build (1, 1, M);
  
  for (int i = 1; i <= m; i++){
    int cnt;
    cin >> cnt;
    ll ans = 0;
    for (int j = 1; j <= cnt; j++)
      cin >> s[i][j];
    s[i][cnt + 1] = M;
	for (int j = 1; j <= cnt; j++){
      ans += get (1, 1, M, 1, s[i][j] + 1, s[i][j], s[i][j + 1]);
	}
	cout << ans << '\n';
  }
}