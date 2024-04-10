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

ll p = 1e9 + 7;

ll mul(ll a, ll b) {
    return (1LL * a%p * b%p) % p;
}

ll add(ll a, ll b) {
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

mt19937 rnd(228);


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> b(n+1);
    for (int i = 0; i<n; i++) cin>>a[i+1]>>b[i+1];
    int counter = 1;
    for (int i = 1; i<=n; i++)
    {
        int t1 = min(a[i], b[i]);
        int t2 = max(a[i-1], b[i-1]);
        if (t1>=t2) counter+=(t1-t2+1); 
        if (a[i-1]==b[i-1]) counter--;
    }
    cout<<counter;

}