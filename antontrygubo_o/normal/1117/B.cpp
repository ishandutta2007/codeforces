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

ll p;

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

int inv(int n)
{
    return po(n, p-2);
}

mt19937 rnd(228);



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, k, m;
    cin>>n>>k>>m;
    vector<ll> a(n);
    get(a);
    sort(a.begin(), a.end());
    if (a[n-1]==a[n-2]) {cout<<k*a[n-1]; return 0;}
    else cout<<(k-k/(m+1))*a[n-1] + (k/(m+1))*a[n-2];

}