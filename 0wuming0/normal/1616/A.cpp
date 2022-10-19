#include"bits/stdc++.h"
using namespace std;
int num[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<=100;i++)num[i]=0;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            num[abs(a)]++;
        }
        int ans=0;
        for(int i=1;i<=100;i++)if(num[i]==1)ans++;
        else if(num[i]>=2)ans+=2;
        if(num[0])ans++;
        cout<<ans<<endl;
    }
    return 0;
}