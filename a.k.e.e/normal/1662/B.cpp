#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=1005;

char str[MAXN];
int cnt[3][26];
int b[3][26],tot[3];
vector<pii> res;

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T=1<<30;
	for(int i=0;i<3;++i)
	{
		scanf("%s",str);
		int len=strlen(str);
		for(int j=0;j<len;++j)++cnt[i][str[j]-'A'];
		chkmin(T,len);
	}
	for(int x=0;x<26;++x)
		while(T)
		{
			int c[3],p[3];
			for(int i=0;i<3;++i)c[i]=cnt[i][x],p[i]=i; 
			sort(p,p+3,[&](int i,int j){return c[i]<c[j];});
			if(!c[p[1]])break;
			--cnt[p[1]][x],--cnt[p[2]][x],++b[p[0]][x],--T;
		}
	for(int i=0;i<3;++i)
		for(int x=0;x<26;++x)
			for(int y=0;y<26;++y)
				while(cnt[i][x] && b[i][y])
					--cnt[i][x],--b[i][y],res.pb(mp(x,y));
	for(int i=0;i<3;++i)
		for(int x=0;x<26;++x)
			tot[i]+=cnt[i][x];
	while(1)
	{
		int p[3];
		for(int i=0;i<3;++i)p[i]=i; 
		sort(p,p+3,[&](int i,int j){return tot[i]<tot[j];});
		if(!tot[p[1]])break;
		int x,y;
		for(int j=0;j<26;++j)if(cnt[p[1]][j]){x=j;break;}
		for(int j=0;j<26;++j)if(cnt[p[2]][j]){y=j;break;}
		--cnt[p[1]][x],--tot[p[1]];
		--cnt[p[2]][y],--tot[p[2]];
		res.pb(mp(x,y));
	}
	for(int i=0;i<3;++i)
		for(int x=0;x<26;++x)
		{
			while(cnt[i][x]--)res.pb(mp(x,x));
			while(b[i][x]--)res.pb(mp(x,x));
		}
	printf("%d\n",res.size());
	for(auto p:res)printf("%c%c\n",p.x+'A',p.y+'A');
	return 0;
}