#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n,l[MAXN],r[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	cin>>l[i]>>r[i];
    sort(l+1,l+n+1);
    sort(r+1,r+n+1);
    ll ans=n;
    for(int i=1;i<=n;i++)
    	ans+=max(l[i],r[i]);
    cout<<ans<<endl;
    return 0;
}