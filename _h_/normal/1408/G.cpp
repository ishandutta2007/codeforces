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

const ll md = 998244353;

vi conv(vi a, vi b){
	vi c(sz(a) + sz(b)-1);
	rep(i,0,sz(a)) rep(j,0,sz(b))
		c[i+j] = (c[i+j] + ll(a[i]) * b[j]) % md;
	return c;
}

void add_to(vi a, vi &b){
	while(sz(b) < sz(a)+1) b.push_back(0);
	rep(i,0,sz(a))
		b[i+1] = (b[i+1] + a[i]) % md;
}

int c2(int n){
	return n * (n-1) / 2;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vector<vi> a(n, vi(n));
	trav(v, a) trav(x, v) cin >> x;

	vector<pair<int, pii>> es;
	rep(j,0,n) rep(i,0,j)
		es.emplace_back(a[i][j], pii(i, j));
	sort(all(es));

	vi pek(n, -1), deg(n), who(n, -1);
	vector<vi> temp(n);

	vi prev;
	vector<vi> mrg;

	function<int(int)> find = [&](int a){
		return pek[a] < 0 ? a : pek[a] = find(pek[a]);
	};
	auto uni = [&](int a, int b){
		a = find(a), b = find(b);	
		if(a != b){
			if(a > b) swap(a, b);
			deg[a] += deg[b];
			pek[a] += pek[b];
			pek[b] = a;
			trav(x, temp[b]) temp[a].push_back(x);
			temp[b].clear();
			temp[a].push_back(who[b]);
		}
		if(++deg[a] == c2(-pek[a])){
			prev.push_back(who[a]);		
			who[a] = sz(mrg);
			mrg.push_back(temp[a]);
			temp[a].clear();
		}
	};
	trav(t, es) uni(t.second.first, t.second.second);
	function<vi(int)> calc = [&](int ix){
		vi sum, prod = {1};
		while(true){
			add_to(prod, sum);
			if(ix >= 0){
				trav(x, mrg[ix]) prod = conv(prod, calc(x));
				ix = prev[ix];
			} else {
				break;
			}
		}
		return sum;
	};
	vi ans = calc(sz(prev)-1);
	rep(k,0,n) cout << ans[k+1] << " ";
	cout << endl;
}