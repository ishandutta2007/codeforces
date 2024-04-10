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
const int N = 1e5 + 10;
char s[N], t[N];
int m, n, mxpr[N], mxsu[N];
int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        cin >> (s + 1) >> (t + 1);
        m = strlen(s + 1);
        n = strlen(t + 1);
        for (int i = 1; i <= m; ++i)
        {
            mxpr[i] = 0;
            while (i + mxpr[i] <= m && mxpr[i] + 1 <= n && s[i + mxpr[i]] == t[mxpr[i] + 1]) ++mxpr[i];
            mxsu[i] = 0;
            while (i + mxsu[i] <= m && n - mxsu[i] >= 1 && s[i + mxsu[i]] == t[n - mxsu[i]]) ++mxsu[i];
            //cout << mxpr[i] << " " << mxsu[i] << "\n";
        }
        bool check = false;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= m; ++j)
            {
                int mid = abs(i - j) + 1;
                if ((n - mid) & 1) continue;
                mid = max(i, j) + (n - mid) / 2;
                if (i + mxpr[i] - 1 >= mid && j + mxsu[j] - 1 >= mid - 1)
                {
                    check = true;
                    break;
                }
            }
        if (check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}