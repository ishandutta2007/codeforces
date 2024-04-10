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
const int N = 2e5 + 10;
char s[N], t[N];
int m, n;
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
        reverse(s + 1, s + m + 1);
        reverse(t + 1, t + n + 1);
        int d = 0, len = 0;
        for (int i = 1; i <= m; ++i)
        {
            if (d == 0)
            {
                if (s[i] == t[len + 1]) len++;
                else d++;
            }
            else d--;
            if (len == n) break;
        }
        if (len == n) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}