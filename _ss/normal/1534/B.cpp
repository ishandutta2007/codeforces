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
const int N = 1e6 + 10;
int a[N], n;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        a[n + 1] = 0;
        ll res = 0;
        for (int i = 1; i <= n; ++i)
        {
            int mx = max(a[i - 1], a[i + 1]);
            if (a[i] > mx) res += a[i] - mx, a[i] = mx;
            res += abs(a[i] - a[i - 1]);
        }
        res += a[n];
        cout << res << "\n";
    }
    return 0;
}