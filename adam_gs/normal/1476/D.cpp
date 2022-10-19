#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
const int LIM=1e5+7, MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		string x;
		cin >> n >> x;
		int l[n+1], p[n+1];
		rep(i, n+1) l[i]=p[i]=0;
		if(x[0]=='L') l[1]=1;
		for(int i=2; i<=n; ++i) {
			if(x[i-1]=='L') {
				l[i]=1;
				if(x[i-2]=='R') l[i]+=l[i-2]+1;
			}
		}
		if(x[n-1]=='R') p[n-1]=1;
		for(int i=n-2; i>=0; --i) {
			if(x[i]=='R') {
				p[i]=1;
				if(x[i+1]=='L') p[i]+=p[i+2]+1;
			}
		}
		rep(i, n+1) cout << l[i]+p[i]+1 << " ";
		cout << '\n';
	}
}