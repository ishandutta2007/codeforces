#include<cstdio>
#include<iostream>
#include<cmath>
#define PI (acos(-1))
#include<queue>
using std::priority_queue;
#include<map>
using std::map;
#include<set>
using std::set;
typedef double db;
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
struct pii
{int x,y;};
inline bool operator<(const pii x,const pii y)
{return x.x<y.x;}
const int ntt=998244353;
const int rq=1e9+7;
using std::cin;
using std::cout;
using std::endl;
#define errlog(...) fprintf(stderr,__VA_ARGS__)
#define In(R) (cin>>R)
#define Out(R) (cout<<R)
#define Ln(R) (cout<<R<<endl)
#define IN In
#define OUT Out
#define OUt Out
#define OuT Out
#define LN Ln
#define iN In
#define oUt Out
#define oUT Out
#define int long long
#define lN Ln
#define Lin Ln 
char str[1111111];
int n,p,v;
int r[111111],s[111111],h[111111],top;
void RD(int t)
{
	int l;
	In(l);
	register int i;
	bool sect=0;
	s[t]=1e9;
	for(i=1;i<=l;i++)
	{
		int a;
		In(a);
		if(a>s[t])sect=1;
		if(a<s[t])s[t]=a;
		if(a>h[t])h[t]=a;
	}if(sect)goto D;
	top++;
	s[top]=s[t],h[top]=h[t];
	return;
	D:
	v++;
}
int solve()
{
	register int i,ii;
	std::sort(s+1,s+top+1);
	std::sort(h+1,h+top+1);
	int ret=0;
	for(i=top,ii=top;i;i--)
	{
		while(s[ii]>=h[i]&&ii)ii--;
		ret+=ii;
	}return ret;
}
void exec()
{
	int G;
	IN(G);
	register int i;
	for(i=1;i<=G;i++)RD(i);
	int r=G-top;
	int ans=G*G-top*top;
	ans+=solve();
	Ln(ans);
}
signed main()
{
	std::ios::sync_with_stdio(0);
	int T=1;
	
	//In(T);
	
	while(T--)exec();
}