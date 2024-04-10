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

int p = 998244353;


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




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll k;
    cin>>k;
    if (k<=1000000)
    {
        cout<<1<<endl;
        cout<<-k<<endl;
        return 0;
    }
    ll n;
    if (k<=100000000)  n = 500;
    else n = 1999;
    ll kek = (k/n)*n;
    if (kek<k) kek+=n;
    ll c = kek-k;
    ll t = (k + (n+1)*(n+c));
    t/=n;
    cout<<n+1<<endl;
    for (int i = 0; i<n-1; i++)
    cout<<-1<<' ';
    cout<<-c-1<<' ';
    cout<<t<<endl;
    

}