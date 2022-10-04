#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=1005,MOD=998244353;

int n,h,a[MAXN],x[MAXN];
bool check(int mid)
{
	ll sum=0;
	for(int i=1;i<=mid;i++)x[i]=a[i];
	sort(x+1,x+mid+1);
	if(mid&1)
		for(int i=1;i<=mid;i+=2)sum+=x[i];
	else
		for(int i=2;i<=mid;i+=2)sum+=x[i];
	return sum<=h;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n>>h;
    for(int i=1;i<=n;i++)cin>>a[i];
    int L=1,R=n,mid,ans=0;
    while(L<=R)
    {
    	mid=(L+R)>>1;
    	if(check(mid))ans=mid,L=mid+1;
    	else R=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}