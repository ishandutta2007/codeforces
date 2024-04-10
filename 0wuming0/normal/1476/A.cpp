#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(n>k)
        {
            if(n%k==0)cout<<1<<endl;
            else cout<<2<<endl;
            continue;
        }
        int ans=k/n;
        if(k%n)ans++;
        cout<<ans<<endl;
    }
    return 0;
}