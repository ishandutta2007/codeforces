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
const int MAXN=200005;
typedef set<int>::iterator iter;

int n;
char str[MAXN];
int toggle(char c)
{
	if(c=='R')return 0;
	if(c=='S')return 1;
	return 2;
}
int a[MAXN];
set<int> st[3],no[3];
int d[3][MAXN];
void add(int o,int x,int y){for(;x<=n;x+=(x&-x))d[o][x]+=y;}
int query(int o,int x){int s=0;for(;x;x-=(x&-x))s+=d[o][x];return s;} 
int work()
{
	int ans=0;
	for(int j=0;j<3;++j)
	{
		if(st[j].empty())continue;
		if((int)st[j].size()==n){ans=n;break;}
		int k=(j+1)%3;
		if(st[k].empty())continue;
		int l=*st[k].begin();
		iter it=st[k].end();
		--it;
		int r=*it;
		ans+=query(j,r)-query(j,l-1);
		ans+=*no[j].begin()-1;
		it=no[j].end();
		--it,--it;
		ans+=n-*it;
//cerr<<j<<":"<<k<<" "<<l<<" "<<r<<" "<<ans<<" "<<*no[j].begin()-1<<" "<<n-*it<<" "<<endl;
	}
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int Q,x,c;
	readint(n),readint(Q);
	scanf("%s",str+1);
	for(int j=0;j<3;++j)
		for(int i=1;i<=n+1;++i)no[j].insert(i);
	for(int i=1;i<=n;++i)
	{
		a[i]=toggle(str[i]);
//cerr<<a[i]<<endl;
		st[a[i]].insert(i);
		no[a[i]].erase(i);
		add(a[i],i,1);
	}
	printf("%d\n",work());
	while(Q--)
	{
		readint(x);scanf("%s",str);
		c=toggle(str[0]);
		st[a[x]].erase(x);
		no[a[x]].insert(x);
		add(a[x],x,-1);
		st[c].insert(x);
		no[c].erase(x);
		add(c,x,1);
		a[x]=c;
		printf("%d\n",work());
	}
	return 0;
}