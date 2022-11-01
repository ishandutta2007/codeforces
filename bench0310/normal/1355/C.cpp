#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    vector<ll> v(b+c+2,0);
    for(ll i=a;i<=b;i++)
    {
        v[i+b]++;
        v[i+c+1]--;
    }
    vector<ll> sum(b+c+2,0);
    for(ll i=1;i<=b+c;i++) sum[i]=sum[i-1]+v[i];
    ll res=0;
    for(ll i=1;i<=b+c;i++) res+=(sum[i]*max(0ll,min(i,d+1)-c));
    cout << res << "\n";
    return 0;
}