#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=120;
int a[V],n,x;
int main()
{
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {scanf("%d",&x);a[x]++;}
        int ret=1;
        int pr=0;
        for(int i=0;i<=100;i++)
        pr+=a[i],ret=max(ret,(i+pr)/(i+1));
        printf("%d\n",ret);
    }
}