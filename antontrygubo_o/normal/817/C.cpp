#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define id pair<int, double>
#define ii pair<id, id>
#define di pair<double, ii>

void print(vector<int> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll p = 1e9 + 9;

ll count (ll n)
{
    ll n1 = n;
    while (n1) 
    {
        n-=n1%10;
        n1/=10;
    }
    return n;
}


int main()
{
    ios_base::sync_with_stdio(0);
    ll n, s;
    cin>>n>>s;
    ll ans = n - min(n, s+200);
    for (ll i = s; i<=min(n, s+200); i++) if (count(i)>=s) ans++;
    cout<<ans;
    
}