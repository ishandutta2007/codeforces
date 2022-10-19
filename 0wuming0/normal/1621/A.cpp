#include"bits/stdc++.h"
using namespace std;
int s[105][105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<105;i++)for(int j=0;j<105;j++)s[i][j]=0;
        if(2*k-1<=n)
        {
            int now=0;
            for(int i=1;;i+=2)
            {
                now++;
                s[i][i]=1;
                if(now==k)break;
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)if(s[i][j]==1)printf("R");
                else printf(".");
                printf("\n");
            }
        }
        else printf("-1\n");
    }
    return 0;
}