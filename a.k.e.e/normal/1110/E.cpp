#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n;
ll a[MAXN],b[MAXN];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%I64d",&b[i]);
    if(a[1]!=b[1] || a[n]!=b[n])return 0*printf("No\n");
    for(int i=n;i>1;i--)a[i]-=a[i-1],b[i]-=b[i-1];
    sort(a+2,a+n+1);
    sort(b+2,b+n+1);
    for(int i=2;i<=n;i++)
    	if(a[i]!=b[i])return 0*printf("No\n");
    printf("Yes\n");
    return 0;
}