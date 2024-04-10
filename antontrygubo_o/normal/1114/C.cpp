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

const ll p = 998244353;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

ll deg_fac(ll n, ll p)
{
    ll res = 0;
    while (n>=p)
    {
        res += (n/p);
        n/=p;
    }
    return res;
}

ll deg(ll n, ll p)
{
    ll counter = 0;
    while (n%p==0)
    {
        counter++;
        n/=p;
    }
    return counter;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    ll n, b;
    cin>>n>>b;
    ll b1 = b;
    ll idx = 2;
    ll minn = 1e18;
    while (b>1)
    {
        while (b%idx!=0&&idx<=sqrt(b)) idx++;
        if (idx>sqrt(b)) idx = b;
        minn = min(minn, deg_fac(n, idx)/deg(b1, idx));
        b/=idx; idx = 2;
    }

    cout<<minn;
    
}