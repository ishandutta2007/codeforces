#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3,P=998244353;
int l[N],r[N],a[N],x[N],w[N],f[N];
int main(){
	int n,k,m,i,j,ans=1,sum,p;
	scanf("%d%d%d",&n,&k,&m);
	for(i=1;i<=m;++i)scanf("%d%d%d",l+i,r+i,x+i);
	while(~(--k)){
		memset(w,0,sizeof w),memset(a,0,sizeof a),sum=1,memset(f,0,sizeof f),f[0]=1,p=0;
		for(i=1;i<=m;++i)if(x[i]>>k&1)++w[l[i]],--w[r[i]+1];else a[r[i]]=max(a[r[i]],l[i]);
		for(i=1;i<=n;++i){
			w[i]+=w[i-1];
			if(!w[i])f[i]=sum,sum=sum*2%P;
			while(p<a[i])sum=(sum-f[p])%P,++p;
		}
		ans=ans*1ll*sum%P;
	}
	printf("%d",(ans+P)%P);
	return 0;
}