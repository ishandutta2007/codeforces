#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

const int p =  998244353;


int mul(int a, int b) {
    return (1LL * a%p * b%p) % p;
}

int add(int a, int b) {
    ll s = (a+b);
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

int inv(int n)
{
    return po(n, p-2);
}



vector<int> Z(string s)
{
int n = s.length();
vector<int> z(n);
int L = 0, R = 0;
for (int i = 1; i < n; i++) {
  if (i > R) {
    L = R = i;
    while (R < n && s[R-L] == s[R]) R++;
    z[i] = R-L; R--;
  } else {
    int k = i-L;
    if (z[k] < R-i+1) z[i] = z[k];
    else {
      L = i;
      while (R < n && s[R-L] == s[R]) R++;
      z[i] = R-L; R--;
    }
  }
}
return z;
}

int n;

vector<ll> Min(4000000, -1e9);
vector<ll> Max(4000000, -1e9);
vector<ll> sum(4000000, -1e9);


void push(ll v)
{
    Min[v*2] = Min[v];
    Min[v*2+1] = Min[v];
    Max[v*2] = Max[v];
    Max[v*2+1] = Max[v];
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll x)
{
    if (Min[v]==Max[v]) {sum[v] = (tr-tl+1)*Min[v]; push(v);}
    if (l>r||Min[v]>=x) return;
    if (tl==l&&tr==r&&Max[v]<=x) 
    {
        Min[v] = x;
        Max[v] = x;
        sum[v] = (tr-tl+1)*x;
        push(v);
    }
    else 
    {
        ll tm = (tl + tr) / 2;
        update (v*2, tl, tm, l, min(r,tm), x);
        update (v*2+1, tm+1, tr, max(l,tm+1), r, x);
        sum[v] = (sum[v*2] + sum[v*2 + 1]);
        Min[v] = min(Min[2*v], Min[2*v+1]);
        Max[v] = max(Max[2*v], Max[2*v+1]);
    }
}



ll get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (Min[v]==Max[v]) {sum[v] = (tr-tl+1)*Min[v]; push(v);}
    if (l>r) return 0;
    if (tl==l&&tr==r) return sum[v];
    ll tm = (tl+tr)/2;
    return get(v*2, tl, tm, l, min(r, tm)) + get(v*2+1, tm+1, tr, max(l, tm+1), r);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n;
    vector<ll> a(n);
    get(a);
    vector<ll> k(n-1);
    get(k);
    
    vector<ll> pref_sum(n);
    pref_sum[0] = 0;
    for (int i = 1; i<n; i++) pref_sum[i] = pref_sum[i-1] + k[i-1];
    vector<ll> prefpref_sum(n);
    prefpref_sum[0] = 0;
    for (int i = 1; i<n; i++) prefpref_sum[i] = prefpref_sum[i-1] + pref_sum[i];
    for (int i = 0; i<n; i++) a[i]-=pref_sum[i];
    for (int i = 0; i<n; i++) update(1, 0, n-1, i, n-1, a[i]);
    
    ll q;
    cin>>q;
    for (int i = 0; i<q; i++)
    {
        char s;
        cin>>s;
        if (s=='+')
        {
            int i, x;
            cin>>i>>x;
            update(1, 0, n-1, i-1, n-1, get(1, 0, n-1, i-1, i-1) + x);
        }
        else
        {
            int l, r;
            cin>>l>>r;
            ll lol = get(1, 0, n-1, l-1, r-1) + prefpref_sum[r-1];
            if (l>=2) lol-=prefpref_sum[l-2];
            cout<<lol<<endl;
        }
    }


}