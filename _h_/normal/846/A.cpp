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

	vi s(n);
	trav(x, s) cin >> x;

	rep(i,0,n+1){
		int cur = 0;
		rep(j,0,n) cur += s[j]==(j>=i);
		ans = max(ans , cur);
	}

	cout << ans << endl;
}