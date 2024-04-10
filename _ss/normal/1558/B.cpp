#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 4e6 + 10;
int ps[N], m, n;

void add(int &x, int y)
{
    x += y;
    if (x >= m) x -= m;
}
int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    ps[1] = 1;
    ps[2] = m - 1;
    int val = 0;
    for (int i = 1; i <= n; ++i)
    {
        add(val, ps[i]);
        add(ps[i + 1], val);
        if (val == 0) continue;
        for (int j = 2, t = 2 * i; t <= n; ++j, t += i)
        {
            add(ps[t], val);
            if (t + j <= n) add(ps[t + j], m - val);
        }
    }
    cout << val;
    return 0;
}