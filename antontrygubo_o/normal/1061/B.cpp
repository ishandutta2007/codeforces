#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;


//vector<vector<int>> a(100, vector<int>(a))


int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    ll summ = 0;
    ll maxx = 0;
    vector<ll> a(n);
    for (int i = 0; i<n; i++)
    {
        cin>>a[i]; summ+=a[i]; maxx = max(maxx, a[i]);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i<n/2; i++) swap(a[i], a[n-1-i]);
    int take = 0;
    for (int i = 0; i<n-1; i++)
    {
        if (a[i]==0)
        {
            a[i+1] = 0;
            take++;
            continue;
        }
        a[i+1] = min(a[i+1], a[i]);
        if (a[i+1]<a[i])
        {
            take+=a[i]-a[i+1];
        }
        else
        {
            take++;
            a[i+1]--;
        }
    }
    take+=a[n-1];
    if (a[n-1]==0) take++;
    cout<<summ-take;
}