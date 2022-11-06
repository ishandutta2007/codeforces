#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<ll> vl;

struct UF {
	vi t;
	UF(int n){
		t.resize(n, -1);
	}
	int find(int a){
		return t[a] < 0 ? a : t[a] = find(t[a]);
	}
	bool uni(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return false;
		if(t[a] < t[b]) swap(a, b);
		t[b] += t[a];
		t[a] = b;
		return true;
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int m, n;
	cin >> m >> n;

	vl a(m), b(n);
	trav(x, a) cin >> x;
	trav(x, b) cin >> x;

	vector<vi> as(m);
	trav(l, as){
		int s;
		cin >> s;
		l.resize(s);
		trav(x, l) cin >> x, --x;
	}

	ll ans = 0;
	vector<pair<ll, pii>> es;
	rep(i,0,m) trav(x, as[i]){
		ll cost = a[i] + b[x];
		ans += cost;
		es.emplace_back(-cost, pii(x, n + i));
	}
	sort(all(es));
	UF uf(n + m);
	trav(t, es){
		if(uf.uni(t.second.first, t.second.second))
			ans += t.first;
	}
	cout << ans << endl;
}