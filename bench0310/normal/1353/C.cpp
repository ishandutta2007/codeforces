#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll res=0;
        for(ll i=3;i<=n;i+=2) res+=((i-1)/2*(i*i-(i-2)*(i-2)));
        cout << res << "\n";
    }
    return 0;
}