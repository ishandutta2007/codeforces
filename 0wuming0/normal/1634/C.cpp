#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if(m==1||n%2==0)
        {
            printf("YES\n");
            for(int i=0;i<n;i++)for(int j=0;j<m;j++)printf("%d%c",j*n+i+1," \n"[j==m-1]);
        }
        else printf("NO\n");
    }
    return 0;
}