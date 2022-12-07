#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL N=1000005;
const LL MOD=200815147;
LL pow[N];
char ss[N];
LL len;
LL a[N],b[N];//
LL sum=0;
LL calc (LL l,LL r)//lr 
{
	return ((sum-b[r+1]-a[l-1]*pow[len-l+1]%MOD)%MOD+MOD)%MOD;
}
bool check (LL l,LL r)// 
{
	if (l<=0) return false;
	if (l+1>r-1)  return false;
	if (((r-1)-(l+1)+1!=1)&&ss[l+1]=='0') return false;
	if (l!=1&&ss[1]=='0') return false;
	LL lalal=((b[r]-a[l])%MOD+MOD)%MOD;	
	lalal=lalal*pow[len-r+1]%MOD;
	if (lalal==calc(l+1,r-1))
		return true;
	return false;
}
int main()
{
	pow[0]=1;for (LL u=1;u<=1000000;u++) pow[u]=pow[u-1]*10%MOD;
	scanf("%s",ss+1);len=strlen(ss+1);
	for (LL u=1;u<=len;u++) sum=(sum*10+ss[u]-'0')%MOD;
	for (LL u=1;u<=len;u++) a[u]=(a[u-1]*10+ss[u]-'0')%MOD;
/*	for (LL u=1;u<=len;u++) printf("%d ",a[u]);
	printf("\n");*/
	for (LL u=len;u>=1;u--) b[u]=(b[u+1]+(ss[u]-'0')*pow[len-u])%MOD;
	LL ans,ans1;
	for (LL u=len;u>=3;u--)//=
	{
		LL t=len-u+1;
		if (t!=1&&ss[u]=='0') continue;
		LL i=len-u+1;// 
		if (check(i,u))
		{
			ans=u;ans1=i;
			break;
		}
		i--;
		if (check(i,u))
		{
			ans=u;ans1=i;
			break;
		}
	//	if (t==9) printf("YES");
		i=u-t;
		if (check(i,u))
		{
			ans=u;ans1=i;
			break;
		}
		i--;
		if (check(i,u))
		{
			ans=u;ans1=i;
			break;
		}
	}
	if (ans!=0)
	{
	for (LL u=1;u<=len;u++)
	{
		if (u==ans) printf("=");
		printf("%c",ss[u]);
		if (u==ans1) printf("+");
	}
	}
	return 0;
}