#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define x first
#define y second
const int MAXN=1005,MOD=998244353;

int n,k,cnt;
int a[MAXN],b[MAXN];
int opc[MAXN*MAXN*2],opx[MAXN*MAXN*2],opy[MAXN*MAXN*2];
bool vis[MAXN];
void add(int u,int tv,int v)
{
	++cnt;
	opc[cnt]=a[u];
	if(!tv){opx[cnt]=(v<=n?2:3);opy[cnt]=(v<=n?v:2*n+1-v);a[v]=a[u];a[u]=0;}
	else {opx[cnt]=(v<=n?1:4);opy[cnt]=(v<=n?v:2*n+1-v);a[u]=0;}
}
bool move(int u)
{
	int pos=-1;
	for(int i=u;i<=2*n;i++)
		if(!a[i]){pos=i;break;}
	if(pos<0)
	{
		for(int i=1;i<u;i++)
			if(!a[i]){pos=i;break;}
		if(pos<0)return 0;
		for(;pos>1;--pos)add(pos-1,0,pos);
		add(2*n,0,1);
		pos=2*n;
	}
	for(;pos>u;--pos)add(pos-1,0,pos);
	return 1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=2*n;i>n;i--)scanf("%d",&a[i]);
    for(int i=2*n;i>n;i--)scanf("%d",&b[i]);
    
    int all=0;
    for(;all<k;)
    {
    	int best=2*n+2,ccc;
	    for(int i=1;i<=2*n;i++)
	    {
	    	if(!b[i] || vis[i])continue;
	    	int pos=0;
	    	for(int j=1;j<=2*n;j++)
	    		if(a[j]==b[i]){pos=j;break;}
	    	if(pos<=i && i-pos<best)best=i-pos,ccc=i;
	    	else if(pos>i && i+2*n-pos<best)best=i+2*n-pos,ccc=i;
	    }
	    int i=ccc;vis[ccc]=1;
    	int pos=0;
    	for(int j=1;j<=2*n;j++)
    		if(a[j]==b[i]){pos=j;break;}
    	while(pos!=i)
		{
			if(!move(pos))return 0*printf("-1\n");
			++pos;
			if(pos>2*n)pos=1;
		}
		add(i,1,i);
		++all;
	}
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++)
    	printf("%d %d %d\n",opc[i],opx[i],opy[i]);
    return 0;
}