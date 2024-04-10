#include<cstdio>
using namespace std;
#define N 525000
#define mod 998244353
int pw(int a,int p){int ans=1;while(p){if(p&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;p>>=1;}return ans;}
int ntt[N],rev[N],s1[N],s2[N],s3[N],s4[N],n,m,a,s[N],as[N];
void dft(int s,int *a,int t)
{
	for(int i=0;i<s;i++)rev[i]=(rev[i>>1]>>1)+(i&1)*s/2;
	for(int i=0;i<s;i++)ntt[rev[i]]=a[i];
	for(int l=2;l<=s;l<<=1)
	{
		int s1=pw(3,(mod-1)/l);
		if(t==-1)s1=pw(s1,mod-2);
		for(int j=0;j<s;j+=l)
		for(int k=j,st=1;k<j+(l>>1);k++,st=1ll*st*s1%mod)
		{
			int a1=ntt[k],a2=1ll*ntt[k+(l>>1)]*st%mod;
			ntt[k]=a1+a2-(a1+a2>=mod?mod:0);
			ntt[k+(l>>1)]=a1-a2+(a1<a2?mod:0);
		}
	}
	int inv=pw(s,t==-1?mod-2:0);
	for(int i=0;i<s;i++)a[i]=1ll*ntt[i]*inv%mod;
}
void getinv(int *v,int x,int *as)
{
	if(x==1){as[0]=pw(v[0],mod-2);return;}
	getinv(v,(x+1)>>1,as);
	int s=1;while(s<x*3)s<<=1;
	for(int i=0;i<s;i++)s1[i]=s2[i]=0;
	for(int i=0;i<x;i++)s1[i]=v[i],s2[i]=as[i];
	dft(s,s1,1);dft(s,s2,1);for(int i=0;i<s;i++)as[i]=1ll*s2[i]*(2-1ll*s1[i]*s2[i]%mod+mod)%mod;dft(s,as,-1);
	for(int i=x;i<s;i++)as[i]=0;
}
void getsqrt(int *v,int x,int *as)
{
	if(x==1){as[0]=1;return;}
	getsqrt(v,(x+1)>>1,as);
	int s=1;while(s<x*2)s<<=1;
	for(int i=0;i<s;i++)s3[i]=0;
	for(int i=0;i<x;i++)s3[i]=as[i];
	dft(s,s3,1);for(int i=0;i<s;i++)s3[i]=1ll*s3[i]*s3[i]%mod;dft(s,s3,-1);
	for(int i=x;i<s;i++)s3[i]=0;
	for(int i=0;i<x;i++)s3[i]=1ll*(s3[i]+v[i])%mod*((mod+1)/2)%mod;
	getinv(as,x,s4);
	dft(s,s4,1);dft(s,s3,1);for(int i=0;i<s;i++)as[i]=1ll*s4[i]*s3[i]%mod;dft(s,as,-1);
	for(int i=x;i<s;i++)as[i]=0;
}
int main()
{
	scanf("%d%d",&n,&m);
	while(n--)scanf("%d",&a),s[a]=mod-4;
	s[0]=1;
	getsqrt(s,m+1,as);
	as[0]++;
	for(int i=0;i<=m;i++)as[i]=1ll*as[i]*(mod+1)/2%mod;
	getinv(as,m+1,s);
	for(int i=1;i<=m;i++)printf("%d\n",s[i]);
}