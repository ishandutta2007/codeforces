#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second 
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define pb push_back

#ifdef BALBIT
#define debug(x) cerr<<__LINE__<<": "<<#x<<" is "<<x<<endl
#define IOS()
#else
#define IOS() ios::sync_with_stdio(0), cin.tie(0)
#define debug(x)
#define endl '\n'
#endif

signed main(){
	IOS();
	int T; cin>>T;
	while (T--){
		int a, b; cin>>a>>b;
		if(__gcd(a,b) != 1) cout<<"Infinite"<<endl;
		else cout<<"Finite"<<endl;
	}
	
}