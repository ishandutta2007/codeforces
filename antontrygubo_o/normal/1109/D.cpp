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


vector<int> fac(1000001);
vector<int> invfac(1000001);

void init()
{
    fac[0] = 1;
    for (int i = 1; i<=1000000; i++) fac[i] = mul(fac[i-1], i);
    for (int i = 0; i<=1000000; i++) invfac[i] = inv(fac[i]);
}

int C(int m, int n)
{
    if (m>n) return 0;
    if (m<0||n<0) return 0;
    return mul(mul(fac[n], invfac[m]), invfac[n-m]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    init();
    ll n, m, a, b;
    cin>>n>>m>>a>>b;
    
    ll res = 0;
    for (int k = 1; k<=min(m, n-1); k++)
    {
        int temp = C(k-1, m-1);
        temp = mul(temp, fac[n-2]);
        temp = mul(temp, invfac[n-k-1]);
        temp = mul(temp, po(m, n-1-k));
        if (k!=n-1)
        {
            temp = mul(temp, po(n, n-k-2));
            temp = mul(temp, k+1);
        }
        res = add(res, temp);
    }
    
    cout<<res;
    

}