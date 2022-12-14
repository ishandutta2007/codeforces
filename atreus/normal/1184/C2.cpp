#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 3e5 + 3;
const int maxp = 2e6 + 10;
const int mod = 1e6 + 7;

int seg[4 * maxp], lazy[4 * maxp];

void propagate(int, int, int);

void add(int id, int L, int R, int l, int r, int val){
	if (R <= l or r <= L)
		return;
	if (l <= L and R <= r){
		seg[id] += val;
		lazy[id] += val;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, l, r, val);
	add(2 * id + 1, mid, R, l, r, val);
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

pair<pair<int, int>, pair<int, int> > a[maxn];

pair<int, int> Rotate(int x, int y){
	return {x + y, x - y};
}

vector<int> cmp;
int getcmp(int v){
	return lower_bound(cmp.begin(), cmp.end(), v) - cmp.begin() + 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, r;
	cin >> n >> r;
	for (int i = 1; i <= n; i++){
		int X, Y;
		cin >> X >> Y;
		a[i] = {Rotate(X - r, Y), Rotate(X + r, Y)};
		cmp.push_back(a[i].first.first);
		cmp.push_back(a[i].first.second);
		cmp.push_back(a[i].second.first + 1);
		cmp.push_back(a[i].second.second + 1);
	}
	vector<pair<int, int> > eve;
	sort(cmp.begin(), cmp.end());
	for (int i = 1; i <= n; i++){
		a[i].first.first = getcmp(a[i].first.first);
		a[i].first.second = getcmp(a[i].first.second);
		a[i].second.first = getcmp(a[i].second.first + 1);
		a[i].second.second = getcmp(a[i].second.second + 1);
		eve.push_back({a[i].first.first, i});
		eve.push_back({a[i].second.first, -i});
	}
	int answer = 0;
	sort(eve.begin(), eve.end());
	for (int i = 0; i < eve.size(); i++){
		pair<int, int> q = eve[i];
		int t = abs(q.second);
		int l = a[t].first.second, r = a[t].second.second;
		if (q.second > 0)
			add(1, 0, maxp, l, r, +1);
		else
			add(1, 0, maxp, l, r, -1);
		if (q == eve.back() or q.first != eve[i + 1].first)
			answer = max(answer, seg[1]);
	}
	cout << answer << endl;
}