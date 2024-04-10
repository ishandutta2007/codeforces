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
vector<ll> sum, emp, maxi;
bool viv = false;
string s;

void swaps()
{
swap(sum[0], sum[1]);
swap(maxi[0], maxi[1]);
swap(emp[0], emp[1]);
}

void steps()
{
if (sum[0] > sum[1])
    swaps();

if (maxi[0] - sum[1] < maxi[1] - sum[0])
    {
    if (emp[1])
        sum[1] += 9, emp[1]--;
    else
        maxi[0] -= 9, emp[0]--;
    }
else
    {
    if (emp[0])
        sum[0] += 9, emp[0]--;
    else
        maxi[1] -= 9, emp[1]--;
    }
if (maxi[0] - sum[1] > maxi[1] - sum[0])
    {
    if (emp[1])
        sum[1] += 9, emp[1]--;
    else
        maxi[0] -= 9, emp[0]--;
    }
else
    {
    if (emp[0])
        sum[0] += 9, emp[0]--;
    else
        maxi[1] -= 9, emp[1]--;
    }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
n/=2;
cin>>s;
sum.resize(2, 0);
emp.resize(2, 0);
maxi.resize(2, 0);
for (i = 0; i < n; i++)
    {
    if (s[i] == '?')
        emp[0]++;
    else
        sum[0] += s[i] - '0';
    }
for (i = 0; i < n; i++)
    {
    if (s[n + i] == '?')
        emp[1]++;
    else
        sum[1] += s[n + i] - '0';
    }

maxi[0] = sum[0] + emp[0] * 9;
maxi[1] = sum[1] + emp[1] * 9;

while (emp[0] + emp[1])
    steps();

ll com = min(maxi[0], maxi[1]) - max(sum[0], sum[1]);

string ans = "carp";
if (com < 0)
    ans = "Mono"+ans;
else
    ans = "Bi"+ans;
cout << ans;


    return 0;
}