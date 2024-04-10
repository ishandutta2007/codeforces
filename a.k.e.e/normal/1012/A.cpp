#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=200005;

int n,a[MAXN];

int main()
{
    cin>>n;
    for(int i=1;i<=n*2;i++)
    	cin>>a[i];
    sort(a+1,a+n*2+1);
    ll ans=(ll)(a[n]-a[1])*(a[n*2]-a[n+1]);
    for(int i=2;i<=n;i++)
    	ans=min(ans,(ll)(a[n*2]-a[1])*(a[n+i-1]-a[i]));
    cout<<ans<<endl;
    return 0;
}