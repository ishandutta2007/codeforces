#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;


ll n, i, j, ans;
vector<ll> a, b;
bool viv = false;
string s;

void change(ll now) {
    ll lans = 0;
    for (ll i = 0; i < n; i++) {
        if (((now - b[i]) % a[i] == 0) && now >= b[i]) {
            if (s[i] == '1')
                s[i] = '0';
            else
                s[i] = '1';
        }

    if (s[i] == '1')
        lans++;
    }
    ans = max(ans, lans);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
cin >> s;
ans = 0;
for (auto i : s)
    if (i == '1')
        ans++;
for (i = 0; i < n; i++) {
    ll la, lb;
    cin >> la >> lb;
    a.push_back(la);
    b.push_back(lb);
    }

for (ll i = 1; i < 100 * kk; i++)
    change(i);
cout << ans;


    return 0;
}