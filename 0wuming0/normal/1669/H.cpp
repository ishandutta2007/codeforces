#include"bits/stdc++.h"
using namespace std;
#define ll long long
int save[31];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<31;i++)save[i]=0;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            for(int j=0;j<=30;j++)if(((1<<j)&a)==0)
            {
                save[j]++;
            }
        }
        int ans=0;
        for(int i=30;i>=0;i--)
        {
            if(k>=save[i])
            {
                k-=save[i];
                ans^=(1<<i);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}