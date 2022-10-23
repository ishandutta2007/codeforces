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

const int N = 1e3 + 10;
int a[N][N];
int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (k > (n + 1) / 2)
        {
            cout << "-1\n";
            continue;
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) a[i][j] = 0;
        for (int i = 1; i <= k; ++i) a[i * 2 - 1][i * 2 - 1] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
                if (a[i][j]) cout << "R";
                else cout << ".";
            cout << "\n";
        }
    }
    return 0;
}