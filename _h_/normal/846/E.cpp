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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<ll> ds(n);
	trav(x, ds) cin >> x;
	rep(i,0,n){
		ll x;
		cin >> x;
		ds[i] -= x;
	}
	vi xs(n), ks(n);
	rep(i,1,n) cin >> xs[i] >> ks[i], --xs[i];
	rrep(i,0,n){
		if(i==0){
			puts(ds[i]<0 ? "NO" : "YES");
			return 0;
		}
		if(ds[i]>0)
			ds[xs[i]] += ds[i];
		else {
			if(double(ds[i])*ks[i] < -1e17){
				puts("NO");
				return 0;
			}
			ds[xs[i]] += ds[i]*ks[i];
			if(ds[xs[i]] < -1e17){
				puts("NO");
				return 0;
			}
		} 
	}
}