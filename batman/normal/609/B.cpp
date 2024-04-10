#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (301*1000)
#define INF ((ll)1e9)

ll n,m,t[22],ans;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        t[a]++;
    }
    for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++)
            ans+=t[i]*t[j];
    cout<<ans;      
        
    return 0;
}