#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
const int INF=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, l=0, ans=INF;
		cin >> n;
		int T[n];
		rep(i, n) cin >> T[i];
		vector<int>V, Q;
		V.push_back(T[0]);
		rep(i, n-1) if(T[i]!=T[i+1]) V.push_back(T[i+1]);
		n=V.size();
		if(V.size()==1) ans=0;
		rep(i, n-1) if(V[i]==V[0]) ++l;
		ans=min(ans, l);
		l=0;
		rep(i, n-1) if(V[i+1]==V[n-1]) ++l;
		ans=min(ans, l);
		l=1;
		rep(i, n-2) Q.push_back(V[i+1]);
		n-=2;
		sort(Q.begin(), Q.end());
		rep(i, n-1) if(Q[i]==Q[i+1]) ++l; else {
			ans=min(ans, l+1);
			l=1;
		}
		ans=min(ans, l+1);
		cout << ans << '\n';
	}
}