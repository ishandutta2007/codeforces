#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=105;

int n,a[MAXN],b[MAXN];

int main()
{
    int m=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i+=2)b[++m]=i;
    for(int i=n;i>0;i--)
    	if(i%2==0)b[++m]=i;
    for(int i=1;i<=n;i++)
    	printf("%d ",a[b[i]]);
    printf("\n");
    return 0;
}