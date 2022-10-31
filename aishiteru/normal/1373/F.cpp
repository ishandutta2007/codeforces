#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=2000005;
int T,n,a[N],b[N];
long long ans,sum,tot; 
int main(){ 
	scanf("%d",&T);it i;
	while(T--){
		scanf("%d",&n),sum=tot=0;
		for(i=1;i<=n;++i) scanf("%d",&a[i]),sum+=a[i];
		for(i=1;i<=n;++i) scanf("%d",&b[i]),sum-=b[i];
		if(sum>0){puts("NO");continue;}
		sum=0;
		for(i=1;i<=n;++i){
			sum+=b[i];
			if(sum>=a[i]) sum-=a[i];
			else tot+=a[i]-sum,sum=0;
		}
		if(tot>b[n]){puts("NO");continue;}
		sum=tot,b[n]-=tot;it fl=1;
		for(i=1;i<=n&&fl;++i)
			if(sum>=a[i]) sum=b[i];
			else sum=sum+b[i]-a[i],fl&=(sum>=0);
		fl?puts("YES"):puts("NO");
	}
	return 0;
}