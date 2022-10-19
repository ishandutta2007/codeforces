#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    int n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int sum[205]={0};
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        {
            int t;
            scanf("%d",&t);
            sum[i+j]^=t;
        }
        for(int i=0;i<205;i++)if(sum[i])
        {
            cout<<"Ashish"<<endl;
            goto ed;
        }
        cout<<"Jeel"<<endl;
        ed:;
    }
    return 0;
}