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
	string s;
	cin >> s;
	int lo = 0, hi = 3*n;
	auto works = [&](int t){
		int togo = -1, seen = n+1;
		rep(i,0,n){
			if(s[i]=='*' && i>togo) seen = min(seen, i);
			if(s[i]=='P'){
				int l = min(seen, i);
				seen = n+1;
				if(i-l > t) return false;
				togo = max(i+t-2*(i-l), i+(t-(i-l))/2);
			}
		}
		return seen==n+1;
	};
	while(lo+1 < hi){
		int mi = (lo+hi)/2;
		if(works(mi))
			hi = mi;
		else
			lo = mi;
	}
	cout << hi << endl;
}