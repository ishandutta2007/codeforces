#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
const int N=200010; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;}
void Solve(){
	ll x=read(),y=read(),ans=0;
	for(ll i=2;i*i-1<=x && i<=y;i++){
		ans+=min((x-(i*i-1))/(i-1)+1,y-i+1);
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