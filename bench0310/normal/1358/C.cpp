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
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        ll x=(c-a+1);
        ll y=(d-b+1);
        ll cnt=x+y-3;
        ll z=min(x,y)-1;
        ll res=2*(z*(z+1)/2);
        res+=(cnt-2*z)*z;
        cout << res+1 << "\n";
    }
    return 0;
}