#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
#define y first
#define x second
const int MAXN=500005,MOD=998244353;

int n;
pii p[MAXN];
int xp[MAXN],yp[MAXN];
int c[MAXN],al[MAXN];
void add(int x,int d)
{
	if(al[x])return;al[x]=1;
	for(;x<=n;x+=(x&-x))c[x]+=d;
}
int query(int x)
{
	int sum=0;
	for(;x;x-=(x&-x))sum+=c[x];
	return sum;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d%d",&p[i].x,&p[i].y);
    	xp[i]=p[i].x;yp[i]=p[i].y;
    }
    sort(xp+1,xp+n+1);
    sort(yp+1,yp+n+1);
    for(int i=1;i<=n;i++)
    	p[i].x=n-(lower_bound(xp+1,xp+n+1,p[i].x)-xp)+1,
    	p[i].y=lower_bound(yp+1,yp+n+1,p[i].y)-yp;
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)p[i].x=n-p[i].x+1;
    ll ans=0;
    for(int i=n;i>0;i--)
    {
    	int nxt=0;
    	if(p[i-1].y==p[i].y)nxt=p[i-1].x-1;
    	else nxt=n;
//cout<<nxt<<" "<<p[i].x<<" "<<p[i].y<<endl;
    	ans+=1ll*(query(p[i].x-1)+1)*(query(nxt)-query(p[i].x)+1);
    	add(p[i].x,1);
    }
    cout<<ans<<endl;
    return 0;
}