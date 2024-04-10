#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

/*const ll p = 1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}*/

ll n, k, a, b;
vector<ll> p;

ll f(ll l, ll r)
{
    if (l==r)
    {
        int c = upper_bound(p.begin(), p.end(), r) - lower_bound(p.begin(), p.end(), r);
        if (c==0) return a;
        else return c*b;
    }
    ll c = upper_bound(p.begin(), p.end(), r) - lower_bound(p.begin(), p.end(), l);
    ll res;
    if (c==0) return a;
    else res = (r-l+1)*c*b;
    res = min(res, f(l, (l+r)/2) + f((l+r)/2+1, r) );
    //cout<<l<<' '<<r<<' '<<res<<endl;
    return res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>k>>a>>b;
    p.resize(k);
    get(p);
    sort(p.begin(), p.end());
    //cout<<(1<<k)<<endl;
    cout<<f(1, 1<<n);
}