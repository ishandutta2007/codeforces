#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a,b,c;
    cin >> a >> b >> c;
    cout << "First" << endl;
    auto q=[&](ll y)
    {
        cout << y << endl;
        int x;
        cin >> x;
        if(x<=0) exit(0);
        if(x==1) a+=y;
        if(x==2) b+=y;
        if(x==3) c+=y;
    };
    q(max({a,b,c}));
    vector<ll> v={a,b,c};
    ranges::sort(v);
    ll x=v[1]-v[0];
    ll y=v[2]-v[1];
    q(x+2*y);
    v={a,b,c};
    ranges::sort(v);
    q(v[1]-v[0]);
    return 0;
}