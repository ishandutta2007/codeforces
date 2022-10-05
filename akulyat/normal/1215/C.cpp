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
vector<ll> m;
bool viv = false;

void bad()
{
cout <<-1;
exit(0);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
string s, t;
cin>>s>>t;
ll kola=0;
for (auto i:t)
    if (i=='a')
        kola++;
for (auto i:s)
    if (i=='a')
        kola++;
if (kola&1)
    bad();

vector <ll> ab;
vector <ll> ba;

for (ll i=0; i<n; i++)
    {
    if (s[i]=='a'&&t[i]=='b')
        ab.push_back(i);
    if (s[i]=='b'&&t[i]=='a')
        ba.push_back(i);
    }

vector <pll> ans;
while (ab.size()>=2)
    ans.push_back({ab[ab.size()-1], ab[ab.size()-2]}),
    ab.pop_back(),
    ab.pop_back();

while (ba.size()>=2)
    ans.push_back({ba[ba.size()-1], ba[ba.size()-2]}),
    ba.pop_back(),
    ba.pop_back();

if (ab.size())
    ans.push_back({ab.back(), ab.back()}),
    ans.push_back({ab.back(), ba.back()});

cout<<ans.size()<<endl;
for (auto i:ans)
    cout<<i.F+1 << ' '<< i.S+1<<'\n';




    return 0;
}