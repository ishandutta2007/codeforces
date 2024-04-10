#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long
#define ld long double
#define mp make_pair

void print(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
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

    ll n;
    cin>>n;
    vector<ll> v(n);
    vector<ll> t(n);
    
    for (int i = 0; i<n; i++) cin>>v[i];
    for (int i = 0; i<n; i++) cin>>t[i];
    
    vector<ll> pref_t(n+1);
    pref_t[0] = 0;
    for (int i = 0; i<n; i++) pref_t[i+1] = pref_t[i] + t[i];
    
    vector<ll> fake(n);
    for (int i = 0; i<n; i++) fake[i] = v[i] + pref_t[i];
    sort(fake.begin(), fake.end());
    vector<ll> fake_melt(n);
    for (int i = 0; i<n; i++) fake_melt[i] = t[i]*(n-1-i);
    
    //print(fake);
    
    //print(fake_melt);
    
    vector<ll> pref_fake(n+1);
    pref_fake[0] = 0;
    for (int i = 0; i<n; i++) pref_fake[i+1] = pref_fake[i] + fake[i];
    
    sort(fake.begin(), fake.end());
    
    vector<ll> melt(n);
    for (int i = 0; i<n; i++)
    {
        ll temp = pref_t[i+1];
        ll k = lower_bound(fake.begin(), fake.end(), temp) - fake.begin();
        melt[i] = pref_fake[k] + (n-k)*temp; 
    }
    
    for (int i = n-2; i>=0; i--) melt[i+1]-=melt[i];
    for (int i = 0; i<n; i++) cout<<melt[i] - fake_melt[i]<<' ';
    

}