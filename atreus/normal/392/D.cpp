#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;

struct node{
	int dp;
	int mnm;
	int mxm;
	int lazy;
};

node seg[4 * maxn];

void propagate(int, int, int);

void change(int id, int L, int R, int l, int r, int x){
	if (seg[id].mnm >= x)
		return;
	int mid = (L + R) >> 1;
	if (L == l and R == r){
		if (seg[id].mnm == seg[id].mxm){
			seg[id].dp += x - seg[id].mnm;
			seg[id].mnm = seg[id].mxm = x;
			seg[id].lazy = x;
			return;
		}
		propagate(id, L, R);
		change(2 * id + 0, L, mid, L, mid, x);
		change(2 * id + 1, mid, R, mid, R, x);
		seg[id].mnm = min(seg[2 * id + 0].mnm, seg[2 * id + 1].mnm);
		seg[id].mxm = max(seg[2 * id + 1].mxm, seg[2 * id + 1].mxm);
		seg[id].dp = min(seg[2 * id + 0].dp, seg[2 * id + 1].dp);
		return;
	}
	propagate(id, L, R);
	if (l < mid)
		change(2 * id + 0, L, mid, l, min(mid, r), x);
	if (mid < r)
		change(2 * id + 1, mid, R, max(l, mid), r, x);
	seg[id].mnm = min(seg[2 * id + 0].mnm, seg[2 * id + 1].mnm);
	seg[id].mxm = max(seg[2 * id + 0].mxm, seg[2 * id + 1].mxm);
	seg[id].dp = min(seg[2 * id + 0].dp, seg[2 * id + 1].dp);
}

void propagate(int id, int L, int R){
	if (seg[id].lazy == 0)
		return;
	int mid = (L + R) >> 1;
	change(2 * id + 0, L, mid, L, mid, seg[id].lazy);
	change(2 * id + 1, mid, R, mid, R, seg[id].lazy);
	seg[id].lazy = 0;
}

void build(int id, int L, int R){
	seg[id].dp = L;
	if (L + 1 == R)
		return;
	int mid = (L + R) >> 1;
	build(2 * id + 0, L, mid);
	build(2 * id + 1, mid, R);
}

int a[5][maxn], last[5][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 1; i <= 3; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
			v.push_back(a[i][j]);
		}
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	memset(last, -1, sizeof last);
	for (int i = 1; i <= 3; i++){
		for (int j = 1; j <= n; j++){
			a[i][j] = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin() + 1;
			if (last[i][a[i][j]] == -1)
				last[i][a[i][j]] = j;
		}
	}
	build(1, 0, n + 1);
	int max_number = v.size();
	int inf = 5 * n;
	for (int i = 1; i <= max_number; i++){
		if (last[1][i] == -1){
			if (last[2][i] == -1)
				change(1, 0, n + 1, 0, n + 1, last[3][i]);
			else{
				if (last[3][i] == -1)
					change(1, 0, n + 1, 0, last[2][i], inf);
				else
					change(1, 0, n + 1, 0, last[2][i], last[3][i]);
			}
		}
	}
	int answer = 3 * n;
	for (int i = n; i >= 0; i--){
		answer = min(answer, seg[1].dp + i);
		if (i == 0)
			break;
		if (last[1][a[1][i]] == i){
			if (last[2][a[1][i]] == -1){
				if (last[3][a[1][i]] == -1)
					break;
				change(1, 0, n + 1, 0, n + 1, last[3][a[1][i]]);
			}
			else{
				if (last[3][a[1][i]] == -1)
					change(1, 0, n + 1, 0, last[2][a[1][i]], inf);
				else
					change(1, 0, n + 1, 0, last[2][a[1][i]], last[3][a[1][i]]);
			}
		}
	}
	cout << answer << endl;
}