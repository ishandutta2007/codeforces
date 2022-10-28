#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, k, ans=INT_MAX, moves=0;
pair<int, int> a[N];

int32_t main()
{
    IOS;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1, a+n+1);
    ans=a[n].first-a[1].first;
    vector<pair<int, int> > v;
    for(int i=1;i<=k;i++)
    {
        if(a[1].first==a[n].first)
            break;
        a[1].first++;
        a[n].first--;
        v.push_back({a[n].second, a[1].second});
        moves++;
        sort(a+1, a+n+1);
    }
    ans=a[n].first-a[1].first;
    cout<<ans<<" "<<moves<<endl;
    for(auto it:v)
        cout<<it.first<<" "<<it.second<<endl;
    return 0;
}