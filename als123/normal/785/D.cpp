#include<bits/stdc++.h>
using namespace std;
#define pa pair<LL,LL>
#define LL long long
const LL MOD=1000000007LL;
const LL Maxn=200010;
char str[Maxn];
LL s1[Maxn],s2[Maxn],ans=0;
LL ooo[Maxn];//
LL get (LL x,LL y)
{
	if (y==1) return x;
	if (y==0) return 1;
	LL lalal=get(x,y>>1);
	lalal=lalal*lalal%MOD;
	if (y&1) lalal=lalal*x%MOD;
	return lalal;
}
LL C(LL n,LL m)
{
	LL re=ooo[n];
	re=re*get(ooo[n-m],MOD-2)%MOD;
	re=re*get(ooo[m],MOD-2)%MOD;
	/*for(LL i=n;i>=n-m+1;i--)re=re*i%MOD;
	for(LL i=m;i;i--) re=re*get(i,MOD-2)%MOD;*/
	return re;
}
int main()
{
	ooo[0]=1;for (LL u=1;u<=200000;u++) ooo[u]=ooo[u-1]*u%MOD;
	scanf("%s",str+1);
	LL len=strlen(str+1);s1[0]=s2[len+1]=0;
	for(LL i=1;i<=len;i++)s1[i]=s1[i-1]+(str[i]=='(');
	for(LL i=len;i;i--)s2[i]=s2[i+1]+(str[i]==')');
	for(LL i=1;i<len;i++)
	if(str[i]=='(')
	{
		LL a=s1[i],b=s2[i+1];
		ans=(ans+C(a+b-1,a))%MOD;
		/*LL lim=min(s1[i],s2[i+1]);
		for(LL j=1;j<=lim;j++)ans=(ans+C(s1[i-1],j-1)*C(s2[i+1],j)%MOD)%MOD;*/
	}
	printf("%lld",ans);
}