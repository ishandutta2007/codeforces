#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define enum(i,x,y) for(int i=(x);i<=(y);++i)
#define try(i,x,y) for(int i=(x);i>=(y);--i)
#define mp make_pair
#define pb push_back
#define x first
#define y second
template <typename TYPE> inline void chkmin(TYPE &a,TYPE b){b<a?a=b:0;}
template <typename TYPE> inline void chkmax(TYPE &a,TYPE b){a<b?a=b:0;}
template <typename TYPE> inline void readint(TYPE &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int MAXN=105;

int n,a[MAXN];
bool vis[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	readint(n);
	enum(i,1,n)readint(a[i]);
	sort(a+1,a+n+1);
	int cnt=0;
	enum(i,1,n)
	{
		if(vis[i])continue;
		enum(j,i,n)
			if(!(a[j]%a[i]))vis[j]=1;
		++cnt;
	}
	printf("%d\n",cnt);
	return 0;
}