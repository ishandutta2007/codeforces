#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 1e9 + 7;

void print(vector<ll> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}


ll fill(ll n)
{
    ll i = max((ll)(sqrt(n))-10, (ll)(0));
    while (i*(i+1)/2<n) i++;
    return i;
}

ll po(ll a, ll d)
{
    if (d==0) return 1;
    if (d%2==1) return (po(a, d-1)*a)%p;
    ll temp = po(a, d/2);
    return (temp*temp)%p;
}

ll inv(ll n)
{
    return po(n, p-2);
}

vector<ll> fac(300050);

vector<ll> invfac(300050);


void init()
{
    fac[0] = 1;
    for (int i = 1; i<300050; i++) fac[i] = (fac[i-1]*i)%p;
    for (int i = 0; i<300050; i++) invfac[i] = inv(fac[i]);
    }

ll C(int n, int k)
{
    if (n<k) return 0;
    ll res = fac[n];
    res = (res*invfac[k])%p;
    res = (res*invfac[n-k])%p;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    string s;
    cin>>s;
    int n = s.length();
    vector<ll> pref_open(n+1);
    pref_open[0] = 0;
    for (int i = 1; i<=n; i++) pref_open[i] = pref_open[i-1] + (s[i-1]=='(');
    
    vector<ll> suf_cl(n+1);
    suf_cl[n] = 0;
    for (int i = n-1; i>=0; i--) suf_cl[i] = suf_cl[i+1] + (s[i]==')');

    //print(pref_open);
    //print(suf_cl);

    ll res = 0;
    for (int i = 1; i<=n; i++) if (s[i-1]=='(') res= (res+C(pref_open[i]-1 + suf_cl[i], pref_open[i]))%p;
    if (res<0) res+=p;
    cout<<res;
    
    
}