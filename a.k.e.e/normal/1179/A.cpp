#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n,a[MAXN*3],u[MAXN*3],v[MAXN*3],front,rear;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int Q;
    ll x;
    scanf("%d%d",&n,&Q);
    front=1;rear=n;
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    for(int i=1;i<=2*n-2;i++)
    {
    	u[i]=a[front],v[i]=a[front+1];
    	if(u[i]<v[i])a[++front]=v[i],a[++rear]=u[i];
    	else a[++front]=u[i],a[++rear]=v[i];
    }
    while(Q--)
    {
    	cin>>x;
    	if(x>n-1)x=x%(n-1)+n-1;
    	printf("%d %d\n",u[x],v[x]);
    }
    return 0;
}