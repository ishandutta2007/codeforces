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

const ll p = 1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, k, m;
    cin>>n>>k>>m;
    vector<ll> a(n);
    get(a);    
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector<ll> pref_sum(n);
    pref_sum[0] = a[0];
    for (int i = 1; i<n; i++) pref_sum[i] = pref_sum[i-1] + a[i];
    ld res = 0;
    for (int i = 1; i<=n; i++) if (m+i>=n)
    {
        ll res1 = pref_sum[i-1] + min(m-(n-i), i*k);
        res = max(res, (ld)(res1)/(ld)(i));
    }
    cout<<setprecision(10)<<res;

}