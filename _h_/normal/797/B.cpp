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
	int ans = 0;
	int mn = 1e5, mx = -1e5;
	rep(_,0,n){
		int x;
		cin >> x;
		if(x&1){
			if(x < 0){
				mx = max(mx, x);
			} else {
				ans += x;
				mn = min(mn, x);
			}
		} else if(x > 0){
			ans += x;
		}
	}
	if(!(ans&1)){
		ans = max(ans + mx, ans - mn);
	}
	cout << ans << endl;
}