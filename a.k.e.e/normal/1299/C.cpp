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
const int MAXN=1000005;

int n;
ll a[MAXN];
int sta[MAXN],top,nxt[MAXN];
double res[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]),a[i]+=a[i-1];
	for(int i=n;i>=0;--i)
	{
		while(top>=2&&(a[sta[top]]-a[i])*(sta[top-1]-i)>(a[sta[top-1]]-a[i])*(sta[top]-i))--top;
		nxt[i]=sta[top];
		sta[++top]=i;
	}
	for(int i=0;i<n;i=nxt[i])
		for(int j=i+1;j<=nxt[i];++j)res[j]=1.0*(a[nxt[i]]-a[i])/(nxt[i]-i);
	for(int i=1;i<=n;++i)printf("%.9lf\n",res[i]);
	return 0;
}