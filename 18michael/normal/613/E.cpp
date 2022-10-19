#include<bits/stdc++.h>
#define bs 233
#define LL long long
#define mod 1000000007
#define Mod 1004535809
using namespace std;
int n,m,ans=0;
int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
char t[2002];
char s[2][2008];
LL Hst[2][2008],pw[2][2008];
LL Hss[2][2][2][2008];
bool ok[2][2008][2][2008];
int f[2][2008][2008];
inline bool check(int x,int y)
{
	return x>=0 && x<2 && y>=1 && y<=n;
}
inline LL getHs(LL *Hs,int l,int r)
{
	return Hs[r]-Hs[l-1]*pw[0][r-l+1];
}
inline LL getHs2(LL *Hs,int l,int r)
{
	return Hs[l]-Hs[r+1]*pw[0][r-l+1];
}
inline LL MgetHs(LL *Hs,int l,int r)
{
	return (Hs[r]-Hs[l-1]*pw[1][r-l+1])%Mod;
}
inline LL MgetHs2(LL *Hs,int l,int r)
{
	return (Hs[l]-Hs[r+1]*pw[1][r-l+1])%Mod;
}
inline void upd(int &x,int y)
{
	if((x+=y)>=mod)x-=mod;
}
inline void solve(bool o)
{
	for(int i=1;i<=m;++i)Hst[0][i]=Hst[0][i-1]*bs+t[i],Hst[1][i]=(Hst[1][i-1]*bs+t[i])%Mod;
	for(int i=0;i<2;++i)
		for(int j=1;j<=n;++j)
		{
			ok[i][j][0][(m>>1)-1]=ok[i][j][1][(m>>1)-1]=0;
			for(int k=0;k<=j-1;++k)ok[i][j][0][k]=(getHs2(Hss[0][i][1],j-k,j)*pw[0][k+1]+getHs(Hss[0][i^1][0],j-k,j)==getHs(Hst[0],1,(k+1)<<1) && !((MgetHs2(Hss[1][i][1],j-k,j)*pw[1][k+1]+MgetHs(Hss[1][i^1][0],j-k,j)-MgetHs(Hst[1],1,(k+1)<<1))%Mod));
			for(int k=0;k<=n-j;++k)ok[i][j][1][k]=(getHs(Hss[0][i][0],j,j+k)*pw[0][k+1]+getHs2(Hss[0][i^1][1],j,j+k)==getHs(Hst[0],m-((k+1)<<1)+1,m) && !((MgetHs(Hss[1][i][0],j,j+k)*pw[1][k+1]+MgetHs2(Hss[1][i^1][1],j,j+k)-MgetHs(Hst[1],m-((k+1)<<1)+1,m))%Mod));
			if(!(m&1) && o)ans+=ok[i][j][0][(m>>1)-1];
		}
	for(int i=n;i;--i)
	{
		for(int j=0;j<2;++j)for(int k=1;k<=m;++k)f[j][i][k]=0;
		for(int j=0;j<2;++j)for(int k=0;k<=n-i && ((k+1)<<1)<=m;++k)if(ok[j][i][1][k])upd(f[j][i][m-((k+1)<<1)+1],((k+1)<<1)<m? 1:o);
		for(int j=0;j<2;++j)for(int k=1;k<=m;++k)if(s[j][i]==t[k])upd(f[j][i][k],k<m? f[j][i+1][k+1]:1);
		for(int j=0;j<2;++j)upd(ans,f[j][i][1]);
		for(int j=0;j<2;++j)for(int k=1;k<=m;++k)if(s[j][i]==t[k] && s[j^1][i]==t[k+1])upd(f[j][i][k],f[j^1][i+1][k+2]);
		for(int j=0;j<2;++j)for(int k=0;k<=i-2 && ((k+1)<<1)<m;++k)if(ok[j^1][i-1][0][k])upd(ans,((k+1)<<1)<m? f[j][i][1+((k+1)<<1)]:1);
	}
}
int main()
{
	scanf("%s%s%s",s[0]+1,s[1]+1,t+1),n=strlen(s[0]+1),m=strlen(t+1),pw[0][0]=pw[1][0]=1;
	if(m<=2)
	{
		for(int i=0,ni,nj;i<2;++i)
			for(int j=1;j<=n;++j)
				if(s[i][j]==t[1])
				{
					if(m==1)
					{
						++ans;
						continue;
					}
					for(int o=0;o<4;++o)ans+=(check(ni=i+dx[o],nj=j+dy[o]) && s[ni][nj]==t[2]);
				}
		return 0&printf("%d",ans);
	}
	for(int i=1;i<=max(n,m);++i)pw[0][i]=pw[0][i-1]*bs,pw[1][i]=(pw[1][i-1]*bs)%Mod;
	for(int i=0;i<2;++i)
	{
		for(int j=1;j<=n;++j)Hss[0][i][0][j]=Hss[0][i][0][j-1]*bs+s[i][j],Hss[1][i][0][j]=(Hss[1][i][0][j-1]*bs+s[i][j])%Mod;
		for(int j=n;j;--j)Hss[0][i][1][j]=Hss[0][i][1][j+1]*bs+s[i][j],Hss[1][i][1][j]=(Hss[1][i][1][j+1]*bs+s[i][j])%Mod;
	}
	solve(1);
	for(int i=1;i<=m-i+1;++i)swap(t[i],t[m-i+1]);
	solve(0),printf("%d",ans);
	return 0;
}