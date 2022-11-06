#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;
typedef long long LL;
const int V=100100;
int c[V];
int n,m,x,y,z;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(c,0,sizeof(c));
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(c[x]!=0)
            {
                c[y]=c[x]%3+1;
                c[z]=c[y]%3+1;
            }
            else if(c[y]!=0)
            {
                c[z]=c[y]%3+1;
                c[x]=c[z]%3+1;
            }
            else if(c[z]!=0)
            {
                c[x]=c[z]%3+1;
                c[y]=c[x]%3+1;
            }
            else
            {
                c[x]=1;
                c[y]=2;
                c[z]=3;
            }
        }
        for(int i=1;i<=n;i++)
        printf("%d ",c[i]);puts("");
    }
    return 0;
}