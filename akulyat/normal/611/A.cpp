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


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<ll> week(8, 52);
    week[5]++;
    week[6]++;
    m.resize(31, 12);
    m[30] = 11;
    m[31] = 7;

    if (s2[0] == 'w')
        cout << week[n];
    else
        cout << m[n];




    return 0;
}