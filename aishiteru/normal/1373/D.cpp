#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
il int Min(ct p,ct q){return p<q?p:q;}
int T,n,a[N],b[N],cb;
long long tot,ans,sum,o;
namespace io{
	il char nc(){
		static char buf[100000],*p1=buf,*p2=buf;
		return p1==p2&&((p2=(p1=buf)+fread(buf,1,100000,stdin)),p1==p2)?EOF:*p1++;
	}
	template <class I>
	il void fr(I &num){
		num=0;register char c=nc();it p=1;
		while(c<'0'||c>'9') c=='-'?p=0,c=nc():c=nc();
		while(c>='0'&&c<='9') num=num*10+c-'0',c=nc();
		num=(p?num:-num);
	}
}
using io :: fr;
int main(){ 
	fr(T);it i;
	while(T--){
		fr(n),cb=0,tot=0;
		for(i=0;i<n;++i)
			fr(a[i]),i&1?b[++cb]=a[i]-a[i-1]:tot+=a[i];
		if(n&1) b[++cb]=-a[n-1]; 
		sum=0,ans=0;
		for(i=1;i<=cb;++i)
			sum=sum>0?sum+b[i]:b[i],ans=ans>sum?ans:sum; 
		o=ans;
		b[cb=1]=-a[0];
		for(i=0;i<n-1;++i)
			if(i&1) b[++cb]=a[i]-a[i+1]; 
		sum=0,ans=0;
		for(i=1;i<=cb;++i)
			sum=sum>0?sum+b[i]:b[i],ans=ans>sum?ans:sum;
		printf("%lld\n",(ans>o?ans:o)+tot),ans=o=0;
	}
	return 0;
}