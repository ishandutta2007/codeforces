#include<cstdio>
#include<cstring>
#define LL long long
#define mod 1000000007
int len,t=0;
LL ans=0;
int st[708],to[708]={};
char s[708];
LL f[708][708][3][3];
inline LL dp(int l,int r,int c1,int c2)
{
	if(l+1==r)return ((!c1 || !c2 || c1!=c2) && (!c1 || !c2) && (c1 || c2));
	if(~f[l][r][c1][c2])return f[l][r][c1][c2];
	f[l][r][c1][c2]=0;
	if(to[r]==l)
	{
		if(l && ((!c1 && !c2) || (c1 && c2)))return 0;
		for(int i=0;i<3;++i)if(!i || !c1 || i!=c1)
			for(int j=0;j<3;++j)if(!j || !c2 || j!=c2)
				f[l][r][c1][c2]=(f[l][r][c1][c2]+dp(l+1,r-1,i,j))%mod;
	}
	else
	{
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)if(!i || !j || i!=j)
				f[l][r][c1][c2]=(f[l][r][c1][c2]+dp(l,to[r]-1,c1,i)*dp(to[r],r,j,c2))%mod;
	}
	return f[l][r][c1][c2];
}
int main()
{
	memset(f,-1,sizeof(f)),scanf("%s",s+1),len=strlen(s+1);
	for(int i=1;i<=len;++i)
	{
		if(s[i]=='(')st[++t]=i;
		else to[i]=st[t],--t;
	}
	printf("%lld",dp(0,len+1,0,0));
	return 0;
}