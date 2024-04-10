#include"bits/stdc++.h"
using namespace std;
int main()
{
    int c1,c2,c3,c4;
    int num1[1005]={0};
    cin>>c1>>c2>>c3>>c4;
    int n,m;
    cin>>n>>m;
    int t;
    while(n--)
    {
        cin>>t;
        num1[n]+=t;
    }
    int ans1=0;
    for(int i=0;i<1001;i++)
    {
        ans1+=min(c2,c1*num1[i]);
    }
    ans1=min(ans1,c3);
    int num2[1005]={0};
    while(m--)
    {
        cin>>t;
        num2[m]+=t;
    }
    int ans2=0;
    for(int i=0;i<1001;i++)
    {
        ans2+=min(c2,c1*num2[i]);
    }//cout<<":"<<ans2<<endl;
    ans2=min(ans2,c3);
    cout<<min(ans1+ans2,c4)<<endl;
    return 0;
}