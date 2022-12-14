#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
const int N=400010;
int a[N],b[N];
signed main(){
	int n=read();
	repeat(i,0,n)a[i]=read();
	int ans=0;
	repeat(i,0,26){ //1<<26
		int mod=1<<(i+1);
		repeat(j,0,n)b[j]=a[j]%mod;
		int s=0;
		sort(b,b+n);
		repeat(j,0,n){
			int l,r;
			l=lower_bound(b,b+n,(1<<i)-b[j])-b;
			r=lower_bound(b,b+n,(1<<(i+1))-b[j])-b-1;
			s+=(r-l+1);
			l=lower_bound(b,b+n,(1<<i)+(1<<(i+1))-b[j])-b;
			r=lower_bound(b,b+n,(1<<(i+2))-b[j])-b-1;
			s+=(r-l+1);
			if((b[j]+b[j])&(1<<i))s--;
		}
		if((s/2)&1)ans+=1<<i;
	}
	cout<<ans<<endl;
	return 0;
}