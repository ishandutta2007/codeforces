#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const ll md = 998244353;

int ceildiv(int a, int b){
	return (a + b-1) / b;
}

int floordiv(int a, int b){
	return a/b;
}

void solve(){
	int n;
	cin >> n;
	vi as(n);
	trav(a, as) cin >> a;

	ll ans = 0;

	vector<pair<int, ll>> ps = { {0, 0ll} };

	rep(ix,0,n){
		int a = as[ix];
		vector<pair<int, ll>> nxt;
		int i = sz(ps)-1;
		while(ps[i].first > a) --i;
		ans = (ps[i].second + ans)%md;
		int k = 1;
		do {
			int l1 = ceildiv(a, k);
			while(ps[i].first > floordiv(a, k)) --i;
			nxt.emplace_back(l1, (ps[i].second + ll(ix+1) * (k-1))%md);
			++k;
		} while( ceildiv(a, k) < ceildiv(a, k-1) );
		rrep(l, 1, ceildiv(a, k) ){
			int kk = ceildiv(a, l);
			while(ps[i].first > floordiv(a, kk)) --i;	
			nxt.emplace_back(l, (ps[i].second + ll(ix+1) * (kk-1))%md);
		}

		reverse(all(nxt));
		ps = nxt;
	}

	cout << ans << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		solve();
	}
}