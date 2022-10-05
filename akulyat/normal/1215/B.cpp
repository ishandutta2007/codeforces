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
pll gans;
vector<vector <ll> > m;
bool viv = false;

void solve(vector <ll> m)
{
if (m.empty())
    return;

pll ans = {0, 0};
pll las = {0, 0};
if (m[0]<0)
    las.F++;
else
    las.S++;
ans=las;
ll n=m.size();
for (ll i=1; i<n; i++)
    {
    if (m[i]<0)
        swap(las.F, las.S);
    if (m[i]<0)
        las.F++;
    else
        las.S++;
    ans.F+=las.F;
    ans.S+=las.S;
//    cout << las.F << ' ' << las.S << endl;
    }
gans.F+=ans.F;
gans.S+=ans.S;
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
m.push_back({});
for (i = 0; i < n; i++)
    {
    ll a;
    cin>>a;
    if (a!=0)
        m.back().push_back(a);
    else
        m.push_back({});
    }
for (auto i:m)
    solve(i);
cout<<gans.F<<' '<<gans.S<<' ';





    return 0;
}