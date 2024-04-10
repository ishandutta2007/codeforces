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
const int M = 1e5 + 10;
int n, q, a[maxn], last[maxn], twolast[maxn], d[maxn], A[maxn], B[maxn], tot[maxn], seg[4 * maxn], pre[maxn], nex[maxn], ted[maxn];
pair <pair <int, int>, int> p[maxn];
pair <int, int> rel[maxn];

ll get (int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) / 2;
	ll ret = 0;
	if (mid > l)
		ret += get (2 * id + 0, L, mid, l, min (mid, r));
	if (mid < r)
		ret += get (2 * id + 1, mid, R, max (l, mid), r);
	return ret;
}

void change (int id, int L, int R, int idx, int val){
	seg[id] += val;
	if (L + 1 == R)
		return;
	int mid = (L + R) / 2;
	if (mid > idx)
		change (2 * id + 0, L, mid, idx, val);
	else
		change (2 * id + 1, mid, R, idx, val);
}

bool cmp1 (pair <pair <int, int>, int> p1, pair <pair <int, int>, int> p2){
	if (p1.F.S < p2.F.S)
		return 1;
	if (p1.F.S == p2.F.S and p1.F.F < p2.F.F)
		return 1;
	return 0;
}

bool cmp (pair <int, int> p1, pair <int, int> p2){
	return (p1.S < p2.S) or (p1.S == p2.S and p1.F < p2.F);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> q;
	for (int i = 1; i <= q; i++){
		cin >> p[i].F.F >> p[i].F.S;
		p[i].S = i;
	}
	// finding pre and next...............
	for (int i = 1; i <= n; i++){
		if (last[a[i]] == 0){
			last[a[i]] = i;
			rel[i].F = 1;
		}
		else if (d[a[i]] == 0){
			twolast[a[i]] = last[a[i]];
			rel[last[a[i]]].S = i;
			d[a[i]] = i - last[a[i]];
			last[a[i]] = i;
			rel[i].F = 1;
		}
		else {
			if (i - last[a[i]] == d[a[i]]){
				rel[i].F = rel[last[a[i]]].F;
				rel[last[a[i]]].S = i;
				twolast[a[i]] = last[a[i]];
				last[a[i]] = i;
			}
			else {
				rel[i].F = twolast[a[i]] + 1;
				d[a[i]] = i - last[a[i]];
				rel[last[a[i]]].S = i;
				twolast[a[i]] = last[a[i]];
				last[a[i]] = i;
			}	
		}
	}
	for (int i = 1; i <= n; i++){
		if (rel[i].S == 0){
			rel[i].S = n + 1;
		}
		pre[i] = rel[i].F;
		nex[i] = rel[i].S;
	}
	// END
	sort (p + 1, p + q + 1);
	sort (rel + 1, rel + n + 1);
	for (int i = 1; i <= n; i++)
		change (1, 1, M, nex[i], 1);
	int idx = 1;
	for (int i = 1; i <= q; i++){
		while (idx < p[i].F.F){
			change (1, 1, M, nex[idx], -1);
			idx ++;
		}
		ted[p[i].S] = get (1, 1, M, p[i].F.S + 1, M) - (n - p[i].F.S);
	}
	idx = 1;
	memset (seg, 0, sizeof seg);
	for (int i = 1; i <= q; i++){
		while (rel[idx].F <= p[i].F.F and idx <= n){
			change (1, 1, M, rel[idx].S, 1);
			idx ++;
		}
		tot[p[i].S] = get (1, 1, M, p[i].F.S + 1, M);
	}
	memset (seg, 0, sizeof seg);	
	idx = 1;
	int idx1 = 1;
	for (int i = 1; i <= q; i++){
		while (rel[idx].F <= p[i].F.F and idx <= n){
			change (1, 1, M, rel[idx].S, 1);
			idx ++;
		}
		while (idx1 < p[i].F.F){
			change (1, 1, M, nex[idx1], -1);
			idx1 ++;
		}
		A[p[i].S] = get (1, 1, M, p[i].F.S + 1, M);
	}

	memset (seg, 0, sizeof seg);

	sort (p + 1, p + q + 1, cmp1);
	sort (rel + 1, rel + n + 1, cmp);
	idx = n, idx1 = n;

	for (int i = q; i >= 1; i--){
		while (rel[idx].S > p[i].F.S and idx >= 1){
			change (1, 1, M, rel[idx].F, 1);
			idx --;
		}
		while (idx1 > p[i].F.S){
			change (1, 1, M, pre[idx1], -1);
			idx1 --;
		}
		B[p[i].S] = get (1, 1, M, 1, p[i].F.F + 1);
	}
	for (int i = 1; i <= q; i++)
		cout << ted[i] + (tot[i] == A[i] + B[i]) << endl;
}