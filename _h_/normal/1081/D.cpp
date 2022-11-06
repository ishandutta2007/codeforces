#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

struct UF {
	vi t, cnt;
	int k;
	UF(int n, int k) : k(k){
		t.resize(n,-1);
		cnt.resize(n);
	}
	int find(int a){
		return t[a]<0 ? a : t[a] = find(t[a]);
	}
	bool uni(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return false;
		if(t[a] < t[b]) swap(a,b);
		t[b] += t[a];
		t[a] = b;
		cnt[b] += cnt[a];
		return cnt[b]==k;
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vi xs(k);
	trav(x, xs) cin >> x, --x;

	vector<pair<int,pii>> es(m);

	trav(t, es){
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		t.first = w;
		t.second = pii(u,v);
	}
	sort(all(es));
	UF uf(n, k);
	trav(x, xs) ++uf.cnt[x];
	trav(e, es){
		pii pa = e.second;
		if(uf.uni(pa.first,pa.second)){
			rep(_,0,k) cout << e.first << ' ';
			cout << endl;
			return 0;
		}
	}
}