#include<cstdio>
#include<algorithm>
typedef long long ll;
char s1[1111111];
char s2[1111111];
void reverse(char*str,int l,int r)
{
	while(l<r)
	{char t=str[l];str[l]=str[r],str[r]=t,l++,r--;}
}
ll ans=0;
const ll mod=998244353;
void exec()
{
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s%s",s1+1,s2+1);
	reverse(s1,1,n),reverse(s2,1,m);
	ll val=0,par=1;
	int i;
	for(i=1;i<=n||i<=m;i++)
	{
		if(s1[i]=='1')(val+=par)%=mod;
		if(s2[i]=='1')(ans+=val)%=mod;
		(par*=2)%=mod;
	}printf("%I64d\n",ans%mod);
}
int main()
{
	int T;
	//scanf("%d",&T);
	T=1;
	while(T--)exec();
}