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

const ll p = 78294349;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}

void solve()
{
    ll n;
    cin>>n;
    int k = 0;
    ll cur = 1;
    while (cur<=n) 
    {
        k++; cur*=2;
    }
    //cout<<n<<' '<<k<<' '<<cur<<endl;
    if (n!=cur-1)
    {
        cout<<cur - 1<<endl; return;
    }
    for (int i = 2; i<=sqrt(n); i++) if (n%i==0) {cout<<n/i<<endl; return;}
    cout<<1<<endl;
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int q;
    cin>>q;
    for (int i = 0; i<q; i++) solve();
}