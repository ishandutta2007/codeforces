#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
#define MAXN 400000
int t = 0;
vector <pii> nums[MAXN];
int Ai[MAXN], Bi[MAXN];


struct Seg {
	int l,r,m,Aindex,Bindex;
	Seg* ch[2];
	Seg (int l, int r): l(l), r(r), m(l + r >> 1) {
		Aindex = t++;
		Bindex = t++;
		if (r - l != 1) {
			ch[0] = new Seg(l,m);
			ch[1] = new Seg(m,r);
			nums[Bindex].pb({ch[0]->Bindex, 0});
			nums[Bindex].pb({ch[1]->Bindex, 0});
			nums[ch[0]->Aindex].pb({Aindex, 0});
			nums[ch[1]->Aindex].pb({Aindex, 0});
		} else {
			t--;
			Ai[l] = Aindex;
			Bi[l] = --Bindex;
		}
	}
	void add1 (int v, int a, int b, int w) {
		if (a <= l and r <= b) {
			nums[Ai[v]].pb({Bindex, w});
		} else {
			if (a < m) ch[0]->add1(v, a, b, w);
			if (m < b) ch[1]->add1(v, a, b, w);
		}
	}
	void add2 (int a, int b, int v, int w) {
		if (a <= l and r <= b) {
			nums[Aindex].pb({Ai[v], w});
		} else {
			if (a < m) ch[0]->add2(a, b, v, w);
			if (m < b) ch[1]->add2(a, b, v, w);
		}
	}
};

lli dis[MAXN];

void build_dijkstra(int s) {
	priority_queue <pli, vector<pli>, greater<pli>> pq;
	pq.push({0, Ai[s]});
	dis[Ai[s]] = 0;
	lli d;
	int v;
	while (pq.size()) {
		tie(d, v) = pq.top(); pq.pop();
		if (d > dis[v]) continue;
		for (pii i : nums[v]) {
			if (d + i.Y < dis[i.X]) {
				dis[i.X] = i.Y + d;
				pq.push({dis[i.X], i.X});
			}
		}
	}
}

int main () {
	int n,q,s;
	cin >> n >> q >> s;
	Seg root(0, n);
	while (q--) {
		int a, v, l, r, w;
		cin >> a;
		if (a == 1) {
			cin >> v >> l >> w;
			r = l; l--; v--;
			root.add1(v, l, r, w);
		} else if (a == 2) {
			cin >> v >> l >> r >> w;
			l--; v--;
			root.add1(v, l, r, w);
		} else {
			cin >> v >> l >> r >> w;
			l--; v--;
			root.add2(l, r, v, w);
		}
	}
	fop (i,0,MAXN) dis[i] = 1ll << 60;
	build_dijkstra(s-1);
	fop (i,0,n) {
		if (dis[Ai[i]] == 1ll << 60) dis[Ai[i]] = -1;
		cout << dis[Ai[i]] << " \n"[i == n - 1];
	}
}