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
int a[V],n,m,b[V];
int main()
{
    while(~scanf("%d",&n))
    {
        int ret1=0,ret2=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&m);
            for(int j=0;j<m;j++)
            scanf("%d",&b[j]);
            for(int j=0;j<m/2;j++)ret1+=b[j];
            for(int j=0;j<m/2;j++)ret2+=b[m-1-j];
            if(m%2==0)a[i]=0;
            else a[i]=b[m/2];
        }
        sort(a,a+n);
        int now=0;
        for(int i=n-1;i>=0;i--)
        {
            if(now==0)ret1+=a[i];
            else ret2+=a[i];
            now^=1;
        }
        printf("%d %d\n",ret1,ret2);
    }
}