#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e6+5;

int n, k;
int a[N], f[N]; 

int32_t main()
{
    IOS;
    cin>>n>>k;
    int ans=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[a[i]]++;
    }
    for(int i=1;i<N;i++)
    {
        f[i]+=f[i-1];
    }
    for(int i=1;i<=1e6;i++)
    {
        if(f[i+k]-f[i]>0)
            ans-=(f[i]-f[i-1]);
    }
    cout<<ans;
    return 0;
}