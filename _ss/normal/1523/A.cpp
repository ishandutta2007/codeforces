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
const int N = 1e5 + 10;
int n, m, a[N];
char s[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cin >> (s + 1);
        for (int i = 1; i <= n; ++i) a[i] = s[i] - '0';
        m = min(m, n);
        a[n + 1] = 0;
        for (int i = 1; i <= m; ++i)
        {
            vi vt;
            for (int j = 1; j <= n; ++j)
                if (a[j] == 0 && a[j - 1] != a[j + 1]) vt.eb(j);
            for (int x : vt) a[x] = 1;
        }
        for (int i = 1; i <= n; ++i) cout << a[i];
        cout << "\n";
    }
    return 0;
}