#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(int i=(x);i<=(y);++i)
#define try(i,x,y) for(int i=(x);i>=(y);--i)
inline void chkmax(int &x,int y){x<y?x=y:0;}
inline void chkmin(int &x,int y){x>y?x=y:0;}
int readint()
{
    int x=0;char c;
    for(c=getchar();!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    return x;
}
const int MAXN=200005;
 
int n,a[MAXN],pre[MAXN];
char s[MAXN];
 
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
	#endif
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='(')a[i]=1;
		else a[i]=-1;
	enum(i,1,n)
	{
		pre[i]=pre[i-1]+a[i];
		if(pre[i]<-1)return 0*printf("No\n");
	}
	if(pre[n])return 0*printf("No\n");
	printf("Yes\n");
    return 0;
}