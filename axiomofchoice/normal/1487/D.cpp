#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
const int N=110; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;}
int a[N][N];
void Solve(){
	int n=read(); ll ans=0;
	for(ll a=3;a*a<=n+n-1;a+=2){
		ans++;
	}
	printf("%lld\n",ans);
}
signed main(){
	// freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}