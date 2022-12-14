// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
const int N=200010; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;}
void Solve(){
	int a=read(),b=read(),ans=1e9;
	repeat(i,0,10)if(b+i!=1){
		int n=a,t=b+i,cnt=0;
		while(n)n/=t,cnt++;
		ans=min(ans,(cnt+i));
	}
	printf("%d\n",ans);
}
signed main(){
	// freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}