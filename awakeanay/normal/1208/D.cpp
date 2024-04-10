#include <iostream>

#define int long long

#define INF 100000000000000
#define MAXN 200005
#define left id+1
#define right id+2*(m-l+1)

int seg[2*MAXN];
int n;
int lazy[2*MAXN];

void push(int id, int l, int r) {
	int m = (l+r)/2;
	seg[left] += lazy[id];
	seg[right] += lazy[id];
	lazy[left] += lazy[id];
	lazy[right] += lazy[id];
	lazy[id] = 0;
}

void update(int x, int y, int val, int id = 0, int l = 0, int r = n-1) {
	if(y < l || r < x)
		return;

	if(x <= l && r <= y) {
		seg[id] += val;
		lazy[id] += val;
		return;
	}

	if(lazy[id])
		push(id, l, r);

	int m = (l+r)/2;
	update(x, y, val, left, l, m);
	update(x, y, val, right, m+1, r);

	seg[id] = std::min(seg[left], seg[right]);
}

int query(int l = 0, int r = n-1, int id = 0) {
	if(l == r)
		return l;

	if(lazy[id])
		push(id, l, r);

	int m = (l+r)/2;
	if(seg[right] <= seg[left])
		return query(m+1, r, right);
	else
		return query(l, m, left);
}

signed main() {
	std::cin >> n;

	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		update(i, i, x);
	}

	int ans[n];
	for(int i = 0; i < n; i++) {
		int next = query();
		if(next < n-1)
			update(next+1, n-1, -i-1);
		update(next, next, INF);
		ans[next] = i+1;
	}

	for(int i = 0; i < n; i++)
		std::cout << ans[i] << " ";
	std::cout << std::endl;

	return 0;
}