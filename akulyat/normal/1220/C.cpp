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
string s;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>s;
n = s.size();

vector<ll> las(26, -1);
vector<ll> ans(n);
ans[0] = 1;
ll mini = 0;
for (ll i = 1; i < n; i++) {
    if (s[i] <= s[mini]) {
        mini = i;
        ans[i] = 1;
    } else
        ans[i] = 0;
}

for (auto i : ans)
    if (i == 0)
        cout << "Ann\n";
    else
        cout << "Mike\n";












    return 0;
}