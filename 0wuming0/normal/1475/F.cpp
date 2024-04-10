#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[1005][1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)
        {
            int t;
            scanf("%1d",&t);
            a[i][j]=t;
        }
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)
        {
            int t;
            scanf("%1d",&t);
            a[i][j]^=t;
        }
        for(int i=1;i<n;i++)for(int j=0;j<n;j++)
        {
            a[i][j]^=a[0][j];
        }
        for(int i=1;i<n;i++)for(int j=1;j<n;j++)
        {
            if(a[i][j]!=a[i][0])
            {
                cout<<"no"<<endl;
                goto ne;
            }
        }
        cout<<"yes"<<endl;
        ne:;
    }
    return 0;
}