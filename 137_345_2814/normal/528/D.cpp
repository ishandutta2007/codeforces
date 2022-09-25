#include<cstdio>
#include<cstring>
using namespace std;
#define mod 998244353
#define N 525000
int pw(int a,int p){int ans=1;while(p){if(p&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;p>>=1;}return ans;}
int a[N],b[N],k,ntt[N],as[N],n,m,rev[N],tmp,vl[N];
char s[N],t[N];
void dft(int s,int *a,int t)
{
	for(int i=0;i<s;i++)
	rev[i]=(rev[i>>1]>>1)+(i&1)*(s>>1),ntt[rev[i]]=a[i];
	for(int l=2;l<=s;l<<=1)
	{
		int s1=pw(3,(mod-1)/l);
		if(t==-1)s1=pw(s1,mod-2);
		for(int j=0;j<s;j+=l)
		for(int k=j,st=1;k<j+(l>>1);k++,st=1ll*st*s1%mod)
		tmp=ntt[k],ntt[k]=(tmp+1ll*ntt[k+(l>>1)]*st)%mod,ntt[k+(l>>1)]=(tmp-1ll*ntt[k+(l>>1)]*st%mod+mod)%mod;
	}
	int tp=t==-1?pw(s,mod-2):1;
	for(int i=0;i<s;i++)a[i]=1ll*tp*ntt[i]%mod;
}
void solve(char st)
{
	int l=1;while(l<=n+m+1)l<<=1;
	for(int i=0;i<l;i++)vl[i]=a[i]=b[i]=0;
	for(int i=0;i<n;i++)
	if(s[i]==st)
	{
		if(i-k<0)vl[0]++;else vl[i-k]++;
		vl[i+k+1]--;
	}
	for(int i=1;i<n;i++)vl[i]+=vl[i-1];
	for(int i=0;i<n;i++)if(vl[i])a[i]=1;
	for(int i=0;i<m;i++)if(t[i]==st)b[m-i]=1;
	dft(l,a,1);dft(l,b,1);for(int i=0;i<l;i++)a[i]=1ll*a[i]*b[i]%mod;dft(l,a,-1);
	for(int i=0;i<=n-m;i++)as[i]+=a[i+m];
}
int main()
{
	scanf("%d%d%d%s%s",&n,&m,&k,s,t);
	solve('A');solve('G');solve('C');solve('T');
	int ans=0;
	for(int i=0;i<n+m;i++)if(as[i]>=m)ans++;
	printf("%d\n",ans);
}