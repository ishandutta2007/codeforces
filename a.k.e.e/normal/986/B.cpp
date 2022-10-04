#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN=1000005;

int n,a[MAXN];

int main()
{
    int cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    	while(a[i]!=i)
    	{
    		swap(a[i],a[a[i]]);
    		cnt++;
    	}
    cnt&=1;
    n&=1;
    if(cnt==n)printf("Petr\n");
    else printf("Um_nik\n");
    return 0;
}