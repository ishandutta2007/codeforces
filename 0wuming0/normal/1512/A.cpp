#include"bits/stdc++.h"
using namespace std;
int num[105];
int a[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<105;i++)num[i]=0;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
            num[a[j]]++;
        }
        for(int i=0;i<105;i++)if(num[i]==1)
        {
            for(int k=1;k<=n;k++)
            {
                if(i==a[k])
                {
                    cout<<k<<endl;
                }
            }
        }
    }
    return 0;
}