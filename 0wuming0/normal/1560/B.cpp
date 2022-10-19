#include"bits/stdc++.h"
using namespace std;
int ans[10005];
int nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a<b)swap(a,b);
        int n=(a-b)*2;
        if(a>n||c>n)cout<<-1<<endl;
        else
        {
            int ans=c+n/2;
            ans%=n;
            if(ans==0)ans=n;
            cout<<ans<<endl;
        }
    }
    return 0;
}