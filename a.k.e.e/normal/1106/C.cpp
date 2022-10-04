#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=300005;

int n,a[MAXN];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    ll ans=0;
    for(int i=1;i*2<=n;i++)
    	ans+=(ll)(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
    cout<<ans<<endl;
    return 0;
}