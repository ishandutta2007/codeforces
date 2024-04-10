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

const int mx = 1e5+10;
const ll md = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vi cnt(mx);
	rep(i,0,n){
		int a;
		cin >> a;
		++cnt[a];
	}
	vi tva(mx,1);
	rep(i,1,mx) tva[i] = tva[i-1]*2 % md;
	vector<ll> ans(mx);
	rrep(d,1,mx){
		int c = 0;
		for(int i = d; i < mx; i += d){
			ans[d] -= ans[i];
			c += cnt[i];
		}
		ans[d] += tva[c]-1;
		ans[d] %= md;
	}
	if(ans[1] < 0) ans[1] += md;
	cout << ans[1] << endl;
}