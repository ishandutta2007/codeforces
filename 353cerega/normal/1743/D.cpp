//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

//const ll mod = 1000000007;
const ll mod = 998244353;



void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    while (s.size()>0 and s.back()=='0')
    {
        s.pop_back();
        n--;
    }
    reverse(s.begin(),s.end());
    string mx = s;
    ll st = n;
    for (ll p=1;p<n;p++)
    {
        if (s[p]=='0')
        {
            st = p;
            break;
        }
    }
    for (ll d=1;d<=st;d++)
    {
        string s2 = s;
        for (ll i=0;i+d<n;i++)
        {
            if (s[i]=='1') s2[i+d] = '1';
        }
        if (s2>mx) mx = s2;
    }
    if (mx=="") mx = "0";
    cout << mx << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}