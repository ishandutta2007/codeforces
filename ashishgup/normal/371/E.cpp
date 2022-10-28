#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n, k, bestind=1, bestsum=1e18;
int pref[N];
pair<int, int> a[N];

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1, a+n+1);
    cin>>k;
    for(int i=1;i<=n;i++)
        pref[i]=pref[i-1]+a[i].first;
    int curans=0, contrib=-(k-1)-2;
    for(int i=1;i<=k;i++)
    {
        contrib+=2;
        curans+=contrib*a[i].first;
    }
    bestsum=curans;
    for(int i=k+1;i<=n;i++)
    {
        curans+=contrib*a[i-k].first;
        curans+=contrib*a[i].first;
        curans-=2*(pref[i-1]-pref[i-k]);
        if(curans<bestsum)
        {
            bestsum=curans;
            bestind=i-k+1;
        }
    }
    for(int i=bestind;i<=bestind+k-1;i++)
        cout<<a[i].second<<" ";
    return 0;   
}