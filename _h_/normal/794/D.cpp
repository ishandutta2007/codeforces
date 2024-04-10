#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

ll f(ll x){
	x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
    x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
    x = x ^ (x >> 31);
    return x;
}

void fail(){
	puts("NO");
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	if(m == (ll)n*(n-1)/2){
		cout << "YES" << endl;
		rep(_,0,n) cout << "1 ";
		cout << endl;
		return 0;
	}
	vector<vi> gr(n);
	rep(_,0,m){
		int u,v;
		cin >> u >> v;
		--u, --v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	rep(i,0,n) gr[i].push_back(i);
	trav(v, gr) sort(all(v));
	vector<ll> val(n);
	rep(i,0,n) trav(v, gr[i]) val[i] = f(val[i]+v);
	map<ll,int> repr;
	vi myrep(n);
	rep(i,0,n){
		if(!repr.count(val[i])) repr[val[i]] = i;
		myrep[i] = repr[val[i]];
	}
	vector<vi> gr2(n);
	rep(i,0,n) if(i == myrep[i]){
		trav(j, gr[i]) if(i!=j && j == myrep[j]) gr2[i].push_back(j);
	}
	trav(v, gr2) if(sz(v)>2) fail();
	vi xs(n);
	rep(i,0,n) if(sz(gr2[i])==1){
		function<void(int,int,int)> dfs = [&](int cur, int pr, int ix){
			xs[cur] = ix;
			trav(nxt, gr2[cur]) if(nxt != pr){
				dfs(nxt, cur, ix+1);
				return;
			}
		};
		dfs(i,-1,1);
		break;
	}
	rep(i,0,n) if(i == myrep[i] && xs[i]==0) fail();
	cout << "YES" << endl;
	rep(i,0,n) cout << xs[myrep[i]] << ' ';
	cout << endl;

}