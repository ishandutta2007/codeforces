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
        for (int i = 1, x; i <= n; ++i) cin >> x;
        cout << 3 * n << "\n";
        for (int i = 1; i <= n; i += 2)
            for (int j = 1; j <= 3; ++j)
                for (int d = 2; d >= 1; --d) cout << d << " " << i << " " << i + 1 << "\n";
    }
    return 0;
}