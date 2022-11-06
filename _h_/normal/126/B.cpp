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

const ll md = 1e9+7, x = 13293231LL;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	int n = sz(s);
	vector<ll> pre(n+1), pws(n+1,1);
	rep(i,0,n) pws[i+1] = x*pws[i] % md;
	rep(i,0,n)
		pre[i+1] = (x*pre[i] + s[i])%md;

	auto hsh = [&](int l, int r){
		return (pre[r]-pre[l]*pws[r-l])%md;
	};
	vi suf;
	int mx = 0;
	rep(i,1,n){
		int lo = i, hi = n+1;
		while(lo+1 < hi){
			int mi = (lo+hi)/2;
			if((hsh(i, mi)-hsh(0, mi-i))%md == 0)
				lo = mi;
			else
				hi = mi;
		}
		if(lo == n){
			suf.push_back(n-i);
			mx = max(mx, lo-i-1);
		} else {
			mx = max(mx, lo-i);
		}
	}
	trav(l, suf) if(l <= mx){
		cout << s.substr(0, l) << endl;
		return 0;
	}
	cout << "Just a legend\n";
}