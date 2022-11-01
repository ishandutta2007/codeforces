#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        n++;
        ll res=0;
        for(ll i=0;n>(1ll<<i);i++) res+=((n/(1ll<<i))-1+((n%(1ll<<i))>0));
        cout << res << "\n";
    }
    return 0;
}