#include"bits/stdc++.h"
using namespace std;
int a[1000],n;
int main()
{
    cin>>n;
    int t,x;
    cin>>t;
    while(t--)
    {
        cin>>x;
        a[x]=1;
    }
    cin>>t;
    while(t--)
    {
        cin>>x;
        a[x]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {cout<<"Oh, my keyboard!"<<endl;

            return 0;
        }
    }cout<<"I become the guy."<<endl;
    return 0;
}