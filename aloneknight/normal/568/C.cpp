#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db long double
#define pii pair<int,int>
#define pli pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline ll rd()
{
	ll x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=405;
int n,m,l;char S[30],str[N],ans[N];bitset<N>g[N];
inline int w(char c){return S[c-'a']=='V';}
void dfs(int x,int o)
{
	if(x==n){printf("%s",ans);exit(0);} 
	int fv=1,fc=1;
	rep0(i,0,x)
	{
		fv&=!g[i<<1|w(ans[i])][x<<1];
		fv&=!g[x<<1|1][i<<1|(w(ans[i])^1)];
		fc&=!g[i<<1|w(ans[i])][x<<1|1];
		fc&=!g[x<<1][i<<1|(w(ans[i])^1)];
	}
	for(char i=o?'a':str[x];i<'a'+l;i++)if((w(i)&&fv)||(!w(i)&&fc)){ans[x]=i;dfs(x+1,o|(ans[x]>str[x]));}
}
int main()
{
	scanf("%s%d%d",S,&n,&m);l=strlen(S);
	int o[2]={0,0};rep0(i,0,l)o[S[i]=='V']=1;
	if(!o[0]||!o[1])rep0(i,0,n)g[i<<1|o[0]][i<<1|(o[0]^1)]=1;
	rep(i,1,m)
	{
		int x,y;char p[5],q[5];scanf("%d%s%d%s",&x,p,&y,q);x--;y--;
		x=x<<1|(p[0]=='V');y=y<<1|(q[0]=='V');g[x][y]=g[y^1][x^1]=1;
	}
	rep0(i,0,n*2)g[i][i]=1;
	rep0(k,0,n*2)rep0(i,0,n*2)if(g[i][k])g[i]|=g[k];
	rep0(i,0,n*2)if(g[i][i^1]&&g[i^1][i]){puts("-1");return 0;}
	scanf("%s",str);dfs(0,0);puts("-1");return 0;
}