#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1005;

int a, b, n;
double x[N], y[N], v[N], ans=1e9;

int32_t main()
{
    IOS;
    cin>>a>>b>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i]>>v[i];
        double cur=(x[i]-a)*(x[i]-a) + (y[i]-b)*(y[i]-b);
        cur=sqrt(cur);
        cur/=v[i];
        ans=min(ans, cur);
    }
    cout<<fixed<<setprecision(12)<<ans;
    return 0;
}