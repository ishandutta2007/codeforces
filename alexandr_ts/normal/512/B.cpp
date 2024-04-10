#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll a[1000];
ll c[1000];

map <ll, ll > m[301];

ll gcd(ll a, ll b)
{
    if (a * b > 0)
        gcd(b % a, a);
    else
        return a + b;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ll n;
    //cout << gcd(15, 25) << " " << gcd(0, 12) << " " << gcd(8, 9) << endl;
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> c[i];
    //for (ll i = 0; i < n; i++)
    m[0][a[0]] = c[0];
    m[0][0] = 0;
    for (ll i = 1; i <= n; i++)
        for (map <ll, ll> :: iterator it = m[i - 1].begin(); it != m[i - 1].end(); it++)
        {
            //cout << it->first << " " << it->second << endl;
            if (!(m[i].count(it->first))){
                m[i][it->first] = m[i - 1][it->first];}
            else
                {m[i][it->first] = min(m[i][it->first], m[i - 1][it->first]);}
            if (!(m[i].count(gcd(it->first, a[i]))))
                m[i][gcd(it->first, a[i])] = m[i - 1][it->first] + c[i];
            else
                m[i][gcd(it->first, a[i])] = min(m[i - 1][it->first] + c[i], (ll)m[i][gcd(it->first, a[i])]);
            //cout << "!";
            //cout << m[1][1] << endl;
        }
//    for (ll i = 0; i < n; i++){
//        for (map <ll, ll> :: iterator it = m[i].begin(); it != m[i].end(); it++)
//            cout << it->first << " " << it->second << endl;cout << endl;}
   // map <ll, ll> :: iterator it = m[n - 1].end();
    //cout << it->second;
    if (!(m[n].count(1)))
        cout << -1;
    else
    cout << m[n][1] << endl;
}