#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
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
        int n, m;
        cin >> n >> m;
        int flag[2] = {0, 0};
        for (int i = 1; i <= n; ++i)
        {
            string s;
            cin >> s;
            for (int j = 1; j <= m; ++j)
                if (s[j - 1] == 'R') a[i][j] = 1, flag[1] |= 1 << ((i + j) & 1);
                else if (s[j - 1] == '.') a[i][j] = -1;
                else a[i][j] = 0, flag[0] |= 1 << ((i + j) & 1);
        }
        if (flag[1] == 3 || flag[0] == 3 || (flag[1] == flag[0] && flag[1] != 0))
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int C[2] = {0, 0};
        if (flag[1] == 1 || flag[0] == 2) C[0] = 1;
        else C[1] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                a[i][j] = C[(i + j) & 1];
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
                if (a[i][j]) cout << 'R';
                else cout << 'W';
            cout << "\n";
        }
    }
    return 0;
}