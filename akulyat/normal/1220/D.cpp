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


ll n, i, j;
vector<ll> m, st;
bool viv = false;

ll maxi(ll a){
    ll res = 0;
    while (!(a & 1))
        res++, a >>= 1;
    return res;
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
    st.push_back(maxi(a));
    }
vector <ll> kol(70, 0);
for (auto i : st)
    kol[i]++;
ll want = max_element(kol.begin(), kol.end())-kol.begin();

vector <ll> ans;
for (ll i = 0; i < n; i++)
    if (st[i] != want)
        ans.push_back(m[i]);

cout << ans.size() << endl;
for (auto i : ans)
    cout << i << ' ';





    return 0;
}