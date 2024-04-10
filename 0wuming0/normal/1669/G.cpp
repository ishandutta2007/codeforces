#include"bits/stdc++.h"
using namespace std;
#define ll long long
char s[55][55];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=m;j++)if(s[i][j]=='*')
            {
                for(int k=i+1;k<=n;k++)
                {
                    if(s[k][j]=='.')swap(s[k][j],s[k-1][j]);
                    else break;
                }
            }
        }
        for(int i=1;i<=n;i++)printf("%s\n",s[i]+1);
    }
    return 0;
}