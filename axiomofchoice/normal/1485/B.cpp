// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
const int N=200010; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;}
ll a[N],s[N];
void Solve(){
	int n=read(),q=read(); ll k=read();
	repeat(i,1,n+1)a[i]=read();
	a[0]=0,a[n+1]=k+1;
	repeat(i,1,n+1)s[i]=a[i+1]-a[i-1]-1-1;
	repeat(i,1,n+1)s[i]+=s[i-1];
	while(q--){
		int l=read(),r=read();
		if(l==r)
			printf("%lld\n",k-1);
		else
			printf("%lld\n",s[r-1]-s[l]+k-a[r-1]+a[l+1]-3);
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