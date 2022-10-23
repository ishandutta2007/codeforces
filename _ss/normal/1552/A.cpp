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
char a[N], b[N];
int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n >> (a + 1);
        for (int i = 1; i <= n; ++i) b[i] = a[i];
        sort(b + 1, b + n + 1);
        int res = 0;
        for (int i = 1; i <= n; ++i) res += (a[i] != b[i]);
        cout << res << "\n";
    }
    return 0;
}