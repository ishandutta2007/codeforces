#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=100005;

int n,a[MAXN],nxt[MAXN];
char str[MAXN];
bool vis[MAXN];
vector<int> v[2][2];
set<int> s[2];
void print(int x){for(;x<=n;x=nxt[x])printf("%d ",x);}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=1;i<=n;++i)a[i]=(str[i]=='L');
	s[0].insert(0);s[0].insert(n+1);s[1].insert(0);s[1].insert(n+1);
	for(int i=1;i<=n;++i)s[a[i]].insert(i);
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(vis[i])continue;
		int fin=0;
		for(int x=i,y=a[x];x<=n;x=nxt[x],y=a[x])
		{
			fin=y;
			vis[x]=1;
			nxt[x]=*s[y^1].upper_bound(x);
			s[y].erase(x);
		}
		v[a[i]][fin^1].pb(i);
		++cnt;
	}
//for(int i=1;i<=n;++i)printf("%-3d",i);putchar('\n');
//for(int i=1;i<=n;++i)printf("%-3d",a[i]);putchar('\n');
//for(int i=1;i<=n;++i)printf("%-3d",nxt[i]);putchar('\n');
//cerr<<v[0][0].size()<<" "<<v[0][1].size()<<endl<<v[1][0].size()<<" "<<v[1][1].size()<<endl;
	printf("%d\n",cnt-1);
	if(v[0][1].size()>v[1][0].size())
	{
		for(auto i:v[0][0])print(i);
		print(v[0][1][0]);
		for(auto i:v[1][1])print(i);
		for(int i=1,j=0;i<(int)v[0][1].size() && j<(int)v[1][0].size();++i,++j)
			print(v[1][0][j]),print(v[0][1][i]);
	}
	else if(v[1][0].size())
	{
		for(auto i:v[1][1])print(i);
		print(v[1][0][0]);
		for(auto i:v[0][0])print(i);
		for(int i=1,j=0;i<(int)v[1][0].size() && j<(int)v[0][1].size();++i,++j)
			print(v[0][1][j]),print(v[1][0][i]);
		if(v[1][0].size()==v[0][1].size())print(v[0][1].back());
	}
	else if(v[0][0].size())
		for(auto i:v[0][0])print(i);
	else
		for(auto i:v[1][1])print(i);
	return 0;
}