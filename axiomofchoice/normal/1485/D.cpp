#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
const int N=200010; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;}
void Solve(){
	ll c=720720;
	int n=read(),m=read();
	repeat(i,0,n)
	repeat(j,0,m){
		int x=read(),ans;
		if((i+j)%2==0)ans=c;
		else ans=c+x*x*x*x;
		printf("%d%c",ans," \n"[j==m-1]);
	}
}
signed main(){
	// freopen("data.txt","r",stdin);
	int T=1; // T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}