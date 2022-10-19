#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,l,to_t=1,ans=0;
int fa[25002],fail[25002],c[25002];
char s[1002],t[52];
int to[25002][12];
int f[52][25002][2];
vector<int> vec[25002];
inline void upd(int &x,int y)
{
	if((x+=y)>=mod)x-=mod;
}
inline void calc(int o)
{
	memset(f,0,sizeof(f)),f[0][0][1]=1;
	for(int i=1;i<=l;++i)
		for(int j=0;j<=to_t;++j)
		{
			if(f[i-1][j][0])for(int k=(i==1);k<10;++k)upd(f[i][to[j][k]][0],f[i-1][j][0]);
			if(f[i-1][j][1])
			{
				for(int k=(i==1);k<(t[i]^48);++k)upd(f[i][to[j][k]][0],f[i-1][j][1]);
				upd(f[i][to[j][t[i]^48]][1],f[i-1][j][1]);
			}
		}
	ans=(ans+(long long)(f[l][1][0]+f[l][1][1])*o)%mod;
}
int main()
{
	scanf("%s%s",s+1,t+1),n=strlen(s+1),l=strlen(t+1);
	for(int i=1,now;i+(l>>1)-1<=n;++i)
	{
		now=0;
		for(int j=i;j<=i+(l>>1)-1;now=to[now][s[j]^48],++j)
			if(!to[now][s[j]^48])
			{
				if(j<i+(l>>1)-1)fa[to[now][s[j]^48]=(++to_t)]=now,vec[j-i].push_back(to_t),c[to_t]=(s[j]^48);
				else to[now][s[j]^48]=1;
			}
	}
	for(int i=0,now;i<n;++i)
		for(int j=0;j<vec[i].size();++j)
		{
			for(now=fail[fa[vec[i][j]]];now && !to[now][c[vec[i][j]]];now=fail[now]);
			if(to[now][c[vec[i][j]]] && to[now][c[vec[i][j]]]!=vec[i][j])fail[vec[i][j]]=to[now][c[vec[i][j]]];
			for(int k=0;k<10;++k)if(!to[vec[i][j]][k])to[vec[i][j]][k]=to[fail[vec[i][j]]][k];
		}
	for(int i=0;i<10;++i)to[1][i]=1;
	for(int i=l;i;--i)
		if(t[i]^48)
		{
			--t[i];
			for(int j=i+1;j<=l;++j)t[j]='9';
			break;
		}
	if(t[1]^48)calc(-1);
	scanf("%s",t+1),calc(1);
	return 0&printf("%d",(ans+mod)%mod);
}