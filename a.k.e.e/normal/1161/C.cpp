#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=55;

int n,a[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int cur=n;
    for(int i=1;i<=n;i++)
    	if(a[i]!=a[1]){cur=i-1;break;}
    printf(cur<=n/2?"Alice\n":"Bob\n");
    return 0;
}