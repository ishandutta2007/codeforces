/**
 *    author:  Atrues
 *    created: 25.01.2019 18:52
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 10;

int lef[maxn], v[maxn], rig[maxn];
vector<pair<int, int> > st[maxn], en[maxn];

pair<int, int> seg[4 * maxn];
int lazy[4 * maxn];

void propagate(int, int, int);

void change(int id, int L, int R, int l, int r, int x){
	if (seg[id].first == 0)
		seg[id].second = L;
	if (L == l and R == r){
		seg[id].first += x;
		lazy[id] += x;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	if (l < mid)
		change(2 * id + 0, L, mid, l, min(mid, r), x);
	if (mid < r)
		change(2 * id + 1, mid, R, max(l, mid), r, x);
	seg[id].first = max(seg[2 * id + 0].first, seg[2 * id + 1].first);
	if (seg[id].first == seg[2 * id + 0].first)
		seg[id].second = seg[2 * id + 0].second;
	else
		seg[id].second = seg[2 * id + 1].second;
}

void propagate(int id, int L, int R){
	if (lazy[id] == 0)
		return;
	int mid = (L + R) >> 1;
	change(2 * id + 0, L, mid, L, mid, lazy[id]);
	change(2 * id + 1, mid, R, mid, R, lazy[id]);
	lazy[id] = 0;
}

void add_rec(int lx, int rx, int dy, int uy){
	st[dy].push_back({lx, rx});
	en[uy].push_back({lx, rx});
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> lef[i] >> v[i] >> rig[i];
		add_rec(lef[i], v[i], v[i], rig[i]);
	}
	int m = 300000, mx = 0, x, y;
	for (int i = 1; i <= m; i++){
		for (auto rec : st[i])	
			change(1, 1, m + 1, rec.first, rec.second + 1, +1);
		if (seg[1].first > mx){
			mx = seg[1].first;
			x = seg[1].second;
			y = i;
		}
		for (auto rec : en[i])
			change(1, 1, m + 1, rec.first, rec.second + 1, -1);
	}
	cout << mx << endl;
	for (int i = 0; i < n; i++)
		if (lef[i] <= x and x <= v[i] and v[i] <= y and y <= rig[i])
			cout << i + 1 << " ";
	cout << endl;
}