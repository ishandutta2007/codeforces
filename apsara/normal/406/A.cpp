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
const int V=1010;
int a[V][V],n,Q,op,x;
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        scanf("%d",&a[i][j]);
        int ret=0;
        for(int i=0;i<n;i++)
        ret^=a[i][i];
        scanf("%d",&Q);
        while(Q--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d",&x);
                ret^=1;
            }
            else if(op==2)
            {
                scanf("%d",&x);
                ret^=1;
            }
            else printf("%d",ret);
        }
        puts("");
    }
}