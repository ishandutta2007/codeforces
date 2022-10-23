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

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll sum = 0, mx = -1e9, n;
        cin >> n;
        for (int i = 1, x; i <= n; ++i)
        {
            cin >> x;
            sum += x;
            mx = max(mx, (ll)x);
        }
        sum -= mx;
        printf("%.9f\n",(double)sum / (n - 1) + mx);
    }
    return 0;
}