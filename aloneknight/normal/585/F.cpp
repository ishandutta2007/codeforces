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
const int N=24405,P=1e9+7;
int n,d,tt,ch[N][10],fa[N],p[N],f[55][N],ed[N],q[N],pt[N];char s[N],X[55],Y[55];
void ins(int l,int r)
{
	int x=0;
	rep(i,l,r)
	{
		int c=s[i]-'0';
		if(!ch[x][c])ch[x][c]=++tt;
		x=ch[x][c];
	}
	ed[x]=1;
}
void build()
{
	int ql=0,qr=0;rep(i,0,9)if(ch[0][i])q[++qr]=ch[0][i];
	while(ql<qr)
	{
		int x=q[++ql];
		rep(i,0,9)if(ch[x][i])fa[ch[x][i]]=ch[fa[x]][i],q[++qr]=ch[x][i];else ch[x][i]=ch[fa[x]][i];
	}
}
int calc(char*s)
{
	int ans=0;p[0]=0;
	rep(i,1,d)
	{
		p[i]=ch[p[i-1]][s[i]-'0'];
		if(ed[p[i]])
		{
			rep(j,i+1,d)p[j]=-1,ans=(ans+1ll*(s[j]-'0')*pt[d-j])%P;
			ans++;break;
		}
	}
	memset(f,0,sizeof(f));
	rep0(i,1,s[1]-'0')f[1][ch[0][i]]++;
	for (int i=2;i<=d;i++)
	{
		rep(j,0,tt)if(!ed[j]&&f[i-1][j])rep(k,0,9)f[i][ch[j][k]]=(f[i][ch[j][k]]+f[i-1][j])%P;
		if(p[i]>=0)rep0(j,0,s[i]-'0')f[i][ch[p[i-1]][j]]++;
	}
	rep(j,1,tt)if(ed[j])rep(i,1,d)ans=(ans+1ll*f[i][j]*pt[d-i])%P;return ans;
}
int main()
{
	scanf("%s%s%s",s+1,X+1,Y+1);n=strlen(s+1);d=strlen(X+1);
	rep(i,1,n-d/2+1)ins(i,i+d/2-1);build();
	pt[0]=1;rep(i,1,d)pt[i]=1ll*pt[i-1]*10%P;
	int x=0;
	rep(i,1,d)
	{
		x=ch[x][X[i]-'0'];
		if(ed[x]){printf("%d\n",(calc(Y)-calc(X)+P+1)%P);return 0;}
	}
	printf("%d\n",(calc(Y)-calc(X)+P)%P);return 0;
}