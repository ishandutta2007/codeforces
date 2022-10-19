#include"bits/stdc++.h"
using namespace std;
#define ll long long
int x[70000];
int ans[70000];
int num[70000];
int main()
{
    int flag=0,x0,y0;
    int n;
    cin>>n;
    int a0,b0,c0;
    for(int i=2;i<=n;i++)
    {
        cout<<"XOR 1 "<<i<<endl;
        cin>>x[i];
        if(flag==1)continue;
        if(x[i]==0)flag=1,x0=1,y0=i;
        else if(num[x[i]]>0)flag=1,x0=num[x[i]],y0=i;
        else num[x[i]]=i;
    }
    if(flag)
    {
        int t;
        cout<<"AND "<<x0<<" "<<y0<<endl;
        cin>>t;
        ans[x0]=ans[y0]=t;
        ans[1]=ans[y0]^x[y0];
    }
    else
    {
        int t;
        x0=1;y0=num[1];
        cout<<"AND "<<x0<<" "<<y0<<endl;
        cin>>t;
        ans[1]=t;
        y0=num[2];
        cout<<"AND "<<x0<<" "<<y0<<endl;
        cin>>t;
        ans[1]=ans[1]/2*2+t%2;
    }
    for(int i=2;i<=n;i++)
    {
        ans[i]=ans[1]^x[i];
    }
    cout<<"!";
    for(int i=1;i<=n;i++)cout<<" "<<ans[i];
    cout<<endl;
    return 0;
}