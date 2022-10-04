#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

const int MAXN=100005;

int n,a[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=2;i<n;i+=2)
    	swap(a[i],a[i+1]);
    for(int i=1;i<=n;i++)
    	printf("%d ",a[i]);
    return 0;
}