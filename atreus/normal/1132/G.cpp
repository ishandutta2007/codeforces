#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e6 + 10;

int seg[4 * maxn], lazy[4 * maxn];

void propagate(int, int, int);

int get(int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg[id];
	propagate(id, L, R);
	int mid = (L + R) >> 1, ret = 0;
	if (l < mid)
		ret = max(ret, get(2 * id + 0, L, mid, l, min(mid, r)));
	if (mid < r)
		ret = max(ret, get(2 * id + 1, mid, R, max(l, mid), r));
	return ret;
}

void add(int id, int L, int R, int l, int r, int val = 1){
	if (L == l and R == r){
		seg[id] += val;
		lazy[id] += val;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	if (l < mid)
		add(2 * id + 0, L, mid, l, min(mid, r));
	if (mid < r)
		add(2 * id + 1, mid, R, max(l, mid), r);
	seg[id] = max(seg[2 * id + 0], seg[2 * id + 1]);
}

void propagate(int id, int L, int R){
	if (lazy[id] == 0)
		return;
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, L, mid, lazy[id]);
	add(2 * id + 1, mid, R, mid, R, lazy[id]);
	lazy[id] = 0;
}

int a[maxn], pre[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	a[n] = n + 1;
	stack<int> st;
	st.push(n);
	for (int i = 0; i < n; i++){
		while (a[st.top()] < a[i])
			st.pop();
		pre[i] = st.top();
		if (pre[i] == n)
			pre[i] = -1;
		st.push(i);
	}

	int ptr = 0;
	for (int i = 0; i < n - k + 1; i++){
		while (ptr - i < k){
			add(1, 0, n, pre[ptr] + 1, ptr + 1);
			ptr ++;
		}
		cout << get(1, 0, n, i, i + k) << " ";
	}
}