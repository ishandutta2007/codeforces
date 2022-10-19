#include"bits/stdc++.h"
using namespace std;
int num[5];
int main()
{
    int n;//cout<<!!((4)%4);
    cin>>n;
    while(n--)
    {
        int t;
        scanf("%d",&t);
        num[t]++;
    }
    int ans=0;
    ans+=num[4]+num[2]/2;
    if(num[2]%2)num[1]-=2,ans++;
    num[1]=max(0,num[1]);
    if(num[1]>num[3])ans+=num[3]+(num[1]-num[3])/4+!!(((num[1]-num[3]))%4);
    else ans+=num[3];
    cout<<ans<<endl;
    return 0;
}