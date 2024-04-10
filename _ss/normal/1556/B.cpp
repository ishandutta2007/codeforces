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

int a[N];

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
        cin >> n;
        int cnt[2] = {0, 0};
        for (int i = 1; i <= n; ++i) cin >> a[i], a[i] &= 1, cnt[a[i]]++;
        if (abs(cnt[0] - cnt[1]) > 1)
        {
            cout << "-1\n";
            continue;
        }
        ll cost0 = 0, cost1 = 0;
        for (int i = 1, d = 1; i <= n; ++i)
            if (!a[i]) cost0 += abs(i - d), d += 2;
        for (int i = 1, d = 1; i <= n; ++i)
            if (a[i]) cost1 += abs(i - d), d += 2;
        int res;
        if (cnt[0] > cnt[1]) res = cost0;
        else if (cnt[1] > cnt[0]) res = cost1;
        else res = min(cost0, cost1);
        cout << res << "\n";
    }
    return 0;
}