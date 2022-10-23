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
        int m, n;
        cin >> m >> n;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) a[i][j] = 0;
        for (int j = 1; j <= n; j += 2) a[1][j] = a[m][j] = 1;
        for (int i = 3; i <= m - 2; i += 2) a[i][1] = a[i][n] = 1;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j) cout << a[i][j];
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}