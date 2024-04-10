#include"bits/stdc++.h"
using namespace std;
int Main();
int t=Main();
int main(){};
int Main()
{
    int n,m;
    cin>>n>>m;
    int f=1;
    long long ans=0;
    for(int i=0;i<m;i++)
    {
        int t;
        scanf("%d",&t);
        if(f<=t)ans=ans+t-f;
        else ans=ans+t+n-f;
        f=t;
    }
    cout<<ans<<endl;
    return 0;
}