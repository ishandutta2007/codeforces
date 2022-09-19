// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int n, q;
int a[N];
int p[N];

vector<int> c;
void Dec(int a, int b){
	c.clear();
	int pr;
	while(a != 1){
		pr = p[a];
		c.pb(pr);
		while(a % pr == 0) a /= pr;
	}
	swap(a, b);
	while(a != 1){
		pr = p[a];
		c.pb(pr);
		while(a % pr == 0) a /= pr;
	}
}

struct DisjointSet {
	int par[N];
	DisjointSet (){
		iota(par, par + N, 0);
	}
	int operator [](int u){
		return Find(u);
	}
	int Find(int u){
		return (par[u] == u ? u : par[u] = Find(par[u]));
	}
	bool Unite(int u, int v){
		u = Find(u); v = Find(v);
		if(u == v) return false;
		par[u] = v;
		return true;
	}
};
DisjointSet DSU;

int s[N], t[N];
typedef pair<int, int> pii;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 2; i < N; i++){
		if(p[i]) continue;
		for(int j = i; j < N; j += i)
			p[j] = i;
	}
	for(int i = 0; i < n; i++){
		cin >> a[i];
		Dec(a[i], 1);
		for(int j = 1; j < (int) c.size(); j++)
			DSU.Unite(c[j - 1], c[j]);
	}
	vector< pair<int, int> > QQ;
	for(int i = 0; i < q; i++){
		cin >> s[i] >> t[i];
		s[i] = DSU.Find(p[ a[s[i] - 1] ]);
		t[i] = DSU.Find(p[ a[t[i] - 1] ]);
		QQ.pb({ min(s[i], t[i]), max(s[i], t[i]) });
	}
	sort(all(QQ));
	vector<int> vl(QQ.size(), 0);

	vector<int> cm;
	for(int i = 0; i < n; i++){
		Dec(a[i], a[i] + 1);
		cm.clear();
		for(auto x : c) cm.pb(DSU.Find(x));
		sort(all(cm));
		cm.resize(unique(all(cm)) - cm.begin());
		for(auto x : cm)
			for(auto y : cm){
				if(x < y){
					int idx = lower_bound(all(QQ), pii(x, y)) - QQ.begin();
					if(idx == (int) QQ.size()) continue;
					if(QQ[idx] != pii(x, y)) continue;
					vl[idx] = 1;
				}
			}
	}
	for(int i = 0; i < q; i++){
		if(s[i] > t[i]) swap(s[i], t[i]);
		if(s[i] == t[i]){
			cout << "0\n";
			continue;
		}
		int idx = lower_bound(all(QQ), pii(s[i], t[i])) - QQ.begin();
		if(idx == (int) QQ.size()){
			cout << "2\n";
			continue;
		}
		if(QQ[idx] != pii(s[i], t[i])){
			cout << "2\n";
			continue;
		}
		cout << (vl[idx] == 1 ? 1 : 2) << '\n';
	}
	return 0;
}