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
	vi as(n);
	trav(x, as) cin >> x;
	sort(all(as));
	int l = 2, r = 3;
	while(l > 0 && as[l-1]==as[2]) --l;
	while(r<n && as[r]==as[2]) ++r;
	int N = r-l, K = 3-l;
	ll ans = 1;
	rep(i,1,K+1) ans = ans*(N-i+1)/i;
	cout << ans << endl; 
}