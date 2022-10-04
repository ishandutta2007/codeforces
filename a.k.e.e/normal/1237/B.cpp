#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(int i=(x);i<=(y);++i)
#define try(i,x,y) for(int i=(x);i>=(y);--i)
void readint(int &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
inline void chkmin(int &x,int y){x>y?x=y:0;}
inline void chkmax(int &x,int y){x<y?x=y:0;}
const int MAXN=100005;

int n,disa[MAXN],b[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	int x;
	readint(n);
	enum(i,1,n)
	{
		readint(x);
		disa[x]=i;
	}
	enum(i,1,n)
	{
		readint(b[i]);
		b[i]=disa[b[i]];
	}
	int cur=n+1,ans=0;
	try(i,n,1)
	{
		if(b[i]>cur)++ans;
		chkmin(cur,b[i]);
	}
	printf("%d\n",ans);
	return 0;
}