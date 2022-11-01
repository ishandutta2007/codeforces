#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> c(20,0);
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        for(int j=0;j<20;j++) if(a&(1<<j)) c[j]++;
    }
    vector<ll> v(n);
    for(int j=0;j<20;j++)
    {
        for(int i=0;i<c[j];i++) v[i]^=(1<<j);
    }
    ll res=0;
    for(ll a:v) res+=(a*a);
    cout << res << "\n";
    return 0;
}