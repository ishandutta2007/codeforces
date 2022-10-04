#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=300005;

int n;
ll fx[MAXN],fy[MAXN],x[MAXN],y[MAXN],k;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1;i<=n;i++)cin>>y[i];
    for(int i=1;i<=n;i++)
    {
    	fx[i]=max(0ll,x[i]-(k*y[i]-fx[i-1]));
    	fy[i]=max(0ll,y[i]-(k*x[i]-fy[i-1]));
    	if(fx[i]>k || fy[i]>k)return 0*printf("NO\n");
    }
    printf("YES\n");
	return 0;
}