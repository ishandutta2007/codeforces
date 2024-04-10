#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;

struct Line{
	int a; // shib
	int b; // arz az mabda'
	int idx; // index of line in array
	Line(){
		idx = -1;
	}
	bool operator < (const Line &other) const{
		if (a != other.a)
			return a < other.a;
		return b < other.b;
	}
	ll get_y(int x){
		return 1ll * x * a + b;
	}
};

struct Query{ // _ne struct dare dar miad
	int l;
	int r;
	int t;
	int idx;
	bool operator < (const Query &other) const{
		return t > other.t;
	}
};

Line arr[maxn];
Query q[maxn];
vector<Line> seg[4 * maxn];

bool mustremove(Line fi, Line se, Line th){
	return 1ll * (fi.b - se.b) * (se.a - th.a) < 1ll * (th.b - se.b) * (se.a - fi.a);
}

void add(int id, int L, int R, Line p){
	if (p.idx < L or p.idx >= R)
		return;
	while (!seg[id].empty()){
		if (seg[id].back().b <= p.b)
			seg[id].pop_back();
		else if (seg[id].size() >= 2){
			Line fi = seg[id].back();
			seg[id].pop_back();
			Line se = seg[id].back();
			if (!mustremove(se, fi, p)){
				seg[id].push_back(fi);
				break;
			}
		}
		else
			break;
	}
	seg[id].push_back(p);
	if (L + 1 == R)
		return;
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, p);
	add(2 * id + 1, mid, R, p);
}

Line answer[maxn];

void get(int id, int L, int R, Query p){
	if (p.l >= R or p.r <= L) // halam az injuri segment zadan beham mikhore
		return;
	if (p.l <= L and p.r >= R){
		while (seg[id].size() > 1){
			int sz = seg[id].size() - 1;
			if (seg[id][sz].get_y(p.t) <= seg[id][sz - 1].get_y(p.t))
				seg[id].pop_back();
			else
				break;
		}
		if (answer[p.idx].idx == -1 or answer[p.idx].get_y(p.t) < seg[id].back().get_y(p.t))
			answer[p.idx] = seg[id].back();
		return;
	}
	int mid = (L + R) >> 1;
	get(2 * id + 0, L, mid, p);
	get(2 * id + 1, mid, R, p);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> arr[i].b >> arr[i].a;
		arr[i].idx = i;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
		add(1, 0, n, arr[i]);
	
	for (int i = 0; i < m; i++){
		cin >> q[i].l >> q[i].r >> q[i].t;
		q[i].l --;
		q[i].idx = i;
	}
	sort(q, q + m);
	for (int i = 0; i < m; i++)
		get(1, 0, n, q[i]);
	for (int i = 0; i < m; i++)
		cout << answer[i].idx + 1 << '\n';
}