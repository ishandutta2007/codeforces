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

void fail(){
	puts("NO");
	exit(0);
}

int main(){
	int n;
	cin >> n;
	vi as(n);
	trav(x, as) cin >> x;
	while(n){
		rep(i,1,n) if(abs(as[i] - as[i-1]) >= 2) fail();
		int mx = 0;
		trav(x, as) mx = max(mx, x);
		rep(i,0,n) if(as[i] == mx){
			as.erase(as.begin() + i);
			break;
		}
		--n;
	}
	puts("YES");
}