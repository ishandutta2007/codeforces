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
const int N = 3e5 + 10, MX = 3e5;
int n;
ll cnt[N], contri[N];

void add(int p, ll v, ll bit[])
{
    for (int i = p; i <= MX; i += (i & -i)) bit[i] += v;
}

ll get(int p, ll bit[])
{
    ll res = 0;
    for (int i = min(p, MX); i; i -= (i & -i)) res += bit[i];
    return res;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll sum = 0, res = 0;
    cin >> n;
    for (int i = 1, x; i <= n; ++i)
    {
        cin >> x;
        res += sum;
        res += get(x, cnt) * x - get(x, contri);
        for (int j = 1; j * x <= MX; ++j)
        {
            int d = get(j * x + x - 1, cnt) - get(j * x - 1, cnt);
            res -= (ll)j * x * d;
            res += (ll)x * d;
            add(j * x, j * x, contri);
            add(j * x + x, - j * x, contri);
        }
        add(x, 1, cnt);
        cout << res << " ";
        sum += x;
    }
    return 0;
}