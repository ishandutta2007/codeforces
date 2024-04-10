#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg

const int maxn = 3e3 + 3;

map<string, int> id;
int d[maxn];
map<int, int> vid[maxn];
map<int, int> rv[maxn];
int ver[maxn];
vector<pair<string, int> > raw[maxn];
vector<int> gr[maxn];
pair<int, int> keks[maxn];
map<int, int> best;
map<int, string> names;
int bd[maxn];
int bid[maxn];

int STR = 0;
int TOT = 0;
int n;
int q[5 * maxn];
int qh = 0, qt = 0;

inline void upd(int v){
	int l = keks[v].X, r = keks[v].Y;
	if(bd[l] > d[v] || (bd[l] == d[v] && bid[l] < r)){bd[l] = d[v]; bid[l] = r;}
}

void bfs(){
	while(qh < qt){
		int v = q[qh++];
		int l = keks[v].X, r = keks[v].Y;
		if(bd[l] < d[v] || (bd[l] == d[v] && bid[l] > r))cont;
		I(u, gr[v]){
			if(d[u] == -1){d[u] = d[v] + 1; upd(u); q[qt++] = u;}
		}
	}
}

int main(){
	sync;
	cin >> n;
	int start;
	F(i, 0, n){
		string s;
		int v;
		cin >> s >> v;
		if(!id.count(s))id[s] = STR++;
		int what = id[s];
		names[what] = s;
		if(!vid[what].count(v)){rv[what][TOT] = v; vid[what][v] = TOT++;}
		int cid = vid[what][v];
		int cnt;
		cin >> cnt;
		F(j, 0, cnt){
			string t;
			int u;
			cin >> t >> u;
			raw[cid].push_back({t, u});
		}
		bd[what] = 1e9;
		keks[cid] = {what, v};
		if(i == 0)start = cid;
	}
	F(i, 0, n){
		d[i] = -1;
		I(huy, raw[i]){
			gr[i].push_back(vid[id[huy.X]][huy.Y]);
		}
	}
	d[start] = 0;
	q[qt++] = start;
	bd[keks[start].X] = 0;
	bfs();
	F(i, 0, n){
		if(d[i] == -1)cont;
		if(d[i] == 0)cont;
		int what = keks[i].X, v = keks[i].Y;
		if(what == keks[start].X)cont;
		if(!best.count(what))best[what] = i;
		else{
			int j = best[what];
			if(d[j] > d[i] || (d[j] == d[i] && v > keks[j].Y))best[what] = i;
		}
	}
	map<string, int> ans;
	I(c, best){
		string cu = names[c.X];
		int v = keks[c.Y].Y;
		ans[cu] = v;
	}
	cout << ans.size() << '\n';
	I(c, ans)cout << c.X << ' ' << c.Y << '\n';
	ret 0;
}