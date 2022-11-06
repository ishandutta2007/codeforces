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
const int V=100100;
int s[3][V];
char t[V];
int n,m,x,y;
int main()
{
    while(~scanf("%s",t))
    {
        int n=strlen(t);
        memset(s,0,sizeof(s));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            s[j][i+1]=s[j][i];
            s[t[i]-'x'][i+1]++;
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&x,&y);
            int mx=0,mi=n;
            for(int i=0;i<3;i++)
            {
                mx=max(mx,s[i][y]-s[i][x-1]);
                mi=min(mi,s[i][y]-s[i][x-1]);
            }
            //printf("T %d %d\n",mi,mx);
            if(mi+1>=mx||y-x<2)puts("YES");
            else puts("NO");
        }
    }
    return 0;
}