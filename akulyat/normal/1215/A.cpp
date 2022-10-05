#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;


ll n, i, j;
vector<ll> m;
bool viv = false;

void maxi(ll a1, ll a2, ll k1, ll k2, ll n)
{
ll res=0;
swap(a1, a2);
swap(k1, k2);
while (n >= k2 && a2)
    {
    a2--;
    n-=k2;
    res++;
    }
while (n >= k1  && a1)
    {
    a1--;
    n-=k1;
    res++;
    }
cout<<res<<' ';
}

void mini(ll a1, ll a2, ll k1, ll k2, ll n)
{
ll res = n - a1*(k1-1) - a2*(k2-1);
res = max(0ll, res);
cout<<res<<' ';
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll a1, a2, k1, k2;
cin>>a1>>a2>>k1>>k2>>n;

if (k1>k2)
    swap(k1, k2), swap(a1, a2);

mini(a1, a2, k1, k2, n);
maxi(a1, a2, k1, k2, n);



    return 0;
}