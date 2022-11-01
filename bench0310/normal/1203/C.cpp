#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll g=0;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin >> a;
        g=gcd(g,a);
    }
    int res=0;
    for(ll i=1;i*i<=g;i++) if((g%i)==0) res+=(1+(i*i<g));
    cout << res << "\n";
    return 0;
}