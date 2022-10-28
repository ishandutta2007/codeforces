#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, a, b, ans=0;
int x[N], vx[N], vy[N];
map<int, map<int, int> > m;
map<int, int> sz;

int32_t main()
{
    IOS;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>vx[i]>>vy[i];
        int parl=vx[i] + vy[i]*a;
        int perp=vy[i] - vx[i]*a;
        m[perp][parl]++;
        sz[perp]++;
    }
    for(auto i:m)
    {
        int cur=sz[i.first];
        for(auto j:i.second)
            ans+=(j.second)*(cur-j.second);
    }
    cout<<ans;
    return 0;
}