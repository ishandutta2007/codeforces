#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;

struct node{
	int mxm;
	int mnm;
	int lazy;
	ll sum;
};

node seg[4 * maxn];

void propagate(int, int, int);

ll get(int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg[id].sum;
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	ll ret = 0;
	if (l < mid)
		ret += get(2 * id + 0, L, mid, l, min(mid, r));
	if (mid < r)
		ret += get(2 * id + 1, mid, R, max(l, mid), r);
	return ret;
}

void change(int id, int L, int R, int l, int r, int val){
	if (seg[id].mnm >= val)
		return;
	if (L == l and R == r and seg[id].mxm == seg[id].mnm){
		seg[id].mxm = seg[id].mnm = val;
		seg[id].sum = 1ll * (R - L) * val;
		seg[id].lazy = val;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	if (l < mid)
		change(2 * id + 0, L, mid, l, min(mid, r), val);
	if (mid < r)
		change(2 * id + 1, mid, R, max(l, mid), r, val);
	seg[id].mxm = max(seg[2 * id + 0].mxm, seg[2 * id + 1].mnm);
	seg[id].mnm = min(seg[2 * id + 0].mnm, seg[2 * id + 1].mnm);
	seg[id].sum = seg[2 * id + 0].sum + seg[2 * id + 1].sum;
}

void propagate(int id, int L, int R){
	if (seg[id].lazy == 0)
		return;
	int mid = (L + R) >> 1;
	change(2 * id + 0, L, mid, L, mid, seg[id].lazy);
	change(2 * id + 1, mid, R, mid, R, seg[id].lazy);
	seg[id].lazy = 0;
}

int a[maxn], suf[maxn], last[maxn];
bool pre[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	memset(last, -1, sizeof last);
	for (int i = n; i >= 1; i--){
		suf[i] = suf[i + 1];
		for (int j = 1; j * j <= a[i]; j++){
			if (a[i] % j != 0)
				continue;
			if (last[j] == -1)
				last[j] = i;
			else
				suf[i] = max(suf[i], j);

			if (j * j != a[i]){
				if (last[a[i] / j] == -1)
					last[a[i] / j] = i;
				else
					suf[i] = max(suf[i], a[i] / j);
			}
		}
	}
	for (int i = 1; i <= n + 1; i++)
		change(1, 1, n + 2, i, i + 1, suf[i]);
	ll answer = 0;
	int now = 0;
	for (int i = 0; i < n; i++){
		answer += get(1, 1, n + 2, i + 2, n + 2);
		for (int j = 1; j * j <= a[i + 1]; j++){
			if (a[i + 1] % j != 0)
				continue;
			if (!pre[j])
				pre[j] = 1;
			else
				now = max(now, j);
			
			if (last[j] != -1)
				change(1, 1, n + 2, 1, last[j] + 1, j);
			if (j * j != a[i + 1]){
				if (!pre[a[i + 1] / j])
					pre[a[i + 1] / j] = 1;
				else
					now = max(now, a[i + 1] / j);
				
				if (last[a[i + 1] / j] != -1)
					change(1, 1, n + 2, 1, last[a[i + 1] / j] + 1, a[i + 1] / j);
			}
		}
		change(1, 1, n + 2, 1, n + 2, now);
	}
	cout << answer << endl;
}