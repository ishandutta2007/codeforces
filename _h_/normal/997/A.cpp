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

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	ll x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	int segs = 0;
	rep(i,0,n) if(s[i]=='0' && (i==0 || s[i-1]=='1'))
		++segs;

	ll ans = 0;
	if(segs){
		ans += y;
		--segs;
	}
	ans += segs * min(x,y);

	cout << ans << endl;
}