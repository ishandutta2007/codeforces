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
const int MAXN=500005;

int n,e,d;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
	#endif
	cin>>n>>d>>e;e*=5;
	int ans=1<<30;
	for(;n>=0;n-=e)chkmin(ans,n%d);
	printf("%d\n",ans);
    return 0;
}