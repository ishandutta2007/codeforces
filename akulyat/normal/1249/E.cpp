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


ll n, i, j, c;
vector<ll> a, b, ans, ans1, ans2;
bool viv = false;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> c;
    for (i = 0; i < n-1; i++) {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    for (i = 0; i < n-1; i++) {
        ll x;
        cin >> x;
        b.push_back(x);
    }

    ans.resize(n);
    ans1.resize(n);
    ans2.resize(n);
    ans1[0] = 0;
    ans2[0] = c;

    for (int i = 1; i < n; i++) {
        ans1[i] = min(ans1[i-1], ans2[i-1]) + a[i-1];
        ans2[i] = min(ans2[i-1], ans1[i-1] + c) + b[i-1];
        ans[i] = min(ans1[i], ans2[i]);
    }

    for (auto i : ans)
        cout << i << ' ';

    return 0;
}