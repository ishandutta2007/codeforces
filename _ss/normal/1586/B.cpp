#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e5 + 10;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vi mark(n + 2, 0);
        for (int i = 1, a, b, c; i <= m; ++i)
        {
            cin >> a >> b >> c;
            mark[b] = 1;
        }
        int root = 1;
        for (int i = 1; i <= n; ++i)
            if (!mark[i]) root = i;
        for (int i = 1; i <= n; ++i)
            if (i != root) cout << i << " " << root << "\n";
    }
    return 0;
}