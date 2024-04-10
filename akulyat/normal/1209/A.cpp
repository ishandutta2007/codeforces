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
vector<ll> m;
bool viv = false;

void change() {
    ll a = m[0];
    vector <ll> left;
    for (ll i=0; i<m.size(); i++)
        if (m[i] % m[0])
            left.push_back(m[i]);
    m=left;
    ans++;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i = 0; i < n; i++)
    {
    ll a;
    cin >> a;
    m.push_back(a);
    }
sort(m.begin(), m.end());
while(m.size())
    change();
cout << ans;
    return 0;
}