/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 4e5 + 10;
const int maxl = 23;

int a[maxn], b[maxn], r[maxn], R[maxn], dp[maxn], pd[maxn];
int seg[maxn * maxl][2], lc[maxn * maxl][2], rc[maxn * maxl][2];

int newint[2];
void build(int id, int L, int R){
	if (L + 1 == R)
		return;
	int mid = (L + R) >> 1;
	lc[id][0] = lc[id][0] = newint[0] ++;
	rc[id][0] = rc[id][1] = newint[0] ++;
	newint[1] += 2;

	build(lc[id][0], L, mid);
	build(rc[id][0], mid, R);
}

int get(int id, int L, int R, int l, int r, bool w){
	if (L == l and R == r)
		return seg[id][w];
	int mid = (L + R) >> 1, ret = 0;
	if (l < mid)
		ret = max(ret, get(lc[id][w], L, mid, l, min(mid, r), w));
	if (mid < r)
		ret = max(ret, get(rc[id][w], mid, R, max(l, mid), r, w));
	return ret;
}

int change(int id, int L, int R, int idx, int val, bool w){
	int me = newint[w] ++;
	seg[me][w] = seg[id][w], lc[me][w] = lc[id][w], rc[me][w] = rc[id][w];
	if (L + 1 == R){
		seg[me][w] = max(seg[id][w], val);
		return me;
	}
	int mid = (L + R) >> 1;
	if (idx < mid){
		lc[me][w] = change(lc[id][w], L, mid, idx, val, w);
		seg[me][w] = max(seg[me][w], seg[lc[me][w]][w]);
	}
	else{
		rc[me][w] = change(rc[id][w], mid, R, idx, val, w);
		seg[me][w] = max(seg[me][w], seg[rc[me][w]][w]);
	}
	return me;
}

int idx[maxn], val[maxn];
bool in_all_lis[maxn], atleast_in_one_lis[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> v;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		v.push_back(a[i]);
	}
	for (int i = 1; i <= m; i++)
		cin >> idx[i] >> val[i];
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (int i = 1; i <= n; i++)
		b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	
	int mxnum = v.size() + 2;
	build(1, 0, mxnum);
	r[0] = 1;
	for (int i = 1; i <= n; i++){
		dp[i] = get(r[i - 1], 0, mxnum, 0, b[i], 0) + 1;
		r[i] = change(r[i - 1], 0, mxnum, b[i], dp[i], 0);
	}
	R[n + 1] = 1;
	for (int i = n; i >= 1; i--){
		pd[i] = get(R[i + 1], 0, mxnum, b[i] + 1, mxnum, 1) + 1;
		R[i] = change(R[i + 1], 0, mxnum, b[i], pd[i], 1);
	}
	
	int LIS = get(r[n], 0, mxnum, 0, mxnum, 0);
	for (int i = 1; i <= n; i++){
		if (dp[i] + pd[i] - 1 == LIS){
			atleast_in_one_lis[i] = 1;
			in_all_lis[i] = 1;
		}
	}
	int maximum = -1;
	for (int i = 1; i <= n; i++){
		if (atleast_in_one_lis[i] == 1){
			if (maximum >= b[i])
				in_all_lis[i] = 0;
			maximum = max(maximum, b[i]);
		}
	}
	int minimum = n + 1;
	for (int i = n; i >= 1; i--){
		if (atleast_in_one_lis[i] == 1){
			if (minimum <= b[i])
				in_all_lis[i] = 0;
			minimum = min(minimum, b[i]);
		}
	}

	// Queries
	for (int i = 1; i <= m; i++){
		int t = lower_bound(v.begin(), v.end(), val[i]) - v.begin() + 1;
		bool equ = (t <= v.size() and v[t - 1] == val[i]);
		int s = idx[i];
		
		int lis = get(r[s - 1], 0, mxnum, 0, t, 0) + get(R[s + 1], 0, mxnum, t + equ, mxnum, 1) + 1;
		cout << max(lis, LIS - in_all_lis[s]) << '\n';
	}
}