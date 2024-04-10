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
        ll n,k;
        cin >> n >> k;
        k--;
        while(k--)
        {
            ll a=9;
            ll b=0;
            ll x=n;
            while(x)
            {
                a=min(a,x%10);
                b=max(b,x%10);
                x/=10;
            }
            n+=(a*b);
            if(a==0) break;
        }
        cout << n << "\n";
    }
    return 0;
}