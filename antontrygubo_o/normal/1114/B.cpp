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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n, m, k;
    cin>>n>>m>>k;
    vector<pair<ll, int>> a(n);
    for (int i = 0; i<n; i++) {cin>>a[i].first; a[i].second = i;}
    sort(a.begin(), a.end());
    vector<bool> check(n);
    ll total = 0;
    for (int i = n-m*k; i<n; i++) {total+=a[i].first; check[a[i].second] = true;}
    
    cout<<total<<endl;
    //print(check);
    
    int counter = 0;
    int cur = 0;
    int j = 1;
    for (int i = 0; i<n; i++) 
    {
        cur += check[i];
        if (cur==j*m&&j<k) {cout<<i+1<<' '; j++;}
    }
    
    
}