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
const int maxn = 1e5 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int nex[maxn], a[maxn], b[maxn], ans[maxn], seg[4 * maxn];
vector <int> v[maxn];

int get (int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) / 2;
	int ret = 0;
	if (mid > l)
		ret += get (2 * id + 0, L, mid, l, min (mid, r));
	if (mid < r)
		ret += get (2 * id + 1, mid, R, max (l, mid), r);
	return ret;
}

void change (int id, int L, int R, int x, int val){
	seg[id] += val;
	if (L + 1 == R)
		return;
	int mid = (L + R) / 2;
	if (mid > x)
		change (2 * id + 0, L, mid, x, val);
	else
		change (2 * id + 1, mid, R, x, val);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[a[i]] = n + 2;
	}
	for (int i = n; i >= 1; i--){
		nex[i] = b[a[i]];
		b[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		change (1, 1, n + 2, nex[i], 1);
	
	for (int i = 1; i <= n; i++)
		v[1].PB (i);
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < v[i].size(); j++){
			int idx = i;
			int l = idx, r = n + 1;
			while (r - l > 1){
				int mid = (l + r) / 2;
				int tmp = get (1, 1, n + 2, mid + 1, n + 2);
				if (tmp - (n - mid) <= v[i][j])
					l = mid;
				else
					r = mid;
			}
			v[r].PB (v[i][j]);
			ans[v[i][j]] ++;
		}
		change (1, 1, n + 2, nex[i], -1);
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
}