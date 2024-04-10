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

	string a, b;
	cin >> a >> b;

	int o = 0, z = 0, oo = 0, zo = 0;

	rep(i,0,n){
		if(a[i]=='0'){
			++o;
			if(b[i] =='1') ++oo;
		} else {
			++z;
			if(b[i] =='1') ++zo;
		}
	}
	ll ans = ll(o)*z - ll(oo)*zo;
	cout << ans << endl;
}