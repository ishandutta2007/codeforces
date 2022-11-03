#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define int ll
#define y1 humiuyn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
map<int,int> mp,used;
signed main()
{
    int n,k;
    cin>>n>>k;
    int step=1;
    vector<int> vec;
    while (step<1e16)
    {
        used[step]=1;
        vec.pb(step);
        int p=step;
        step*=k;
        if (used[step]) break;
    }
    mp[0]++;
    int now=0;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        now+=a;
        for (int j=0;j<vec.size();j++)
            ans+=mp[now-vec[j]];
        mp[now]++;
    }
    cout<<ans;
}