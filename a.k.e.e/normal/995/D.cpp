#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define x first
#define y second
const int MAXN=1000005,MOD=998244353;

int n,c[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int Q,u,w;
    ll s=0;
    scanf("%d%d",&n,&Q);
    for(int i=0;i<(1<<n);i++)
    	{scanf("%d",&c[i]);s+=c[i];}
    printf("%.9lf\n",1.0*s/(1<<n));
    while(Q--)
    {
    	scanf("%d%d",&u,&w);
    	s+=w-c[u];
    	c[u]=w;
    	printf("%.9lf\n",1.0*s/(1<<n));
    }
    return 0;
}