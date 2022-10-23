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
        int a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        int n = a + b;
        if (n & 1)
        {
            int mn = (a - b) / 2;
            cout << (n - 2 * mn + 1) << "\n";
            for (int i = mn; i <= n - mn; ++i) cout << i << " ";
            cout << "\n";
        }
        else
        {
            int mn = (a - b) / 2;
            cout << (n - 2 * mn) / 2 + 1 << "\n";
            for (int i = mn; i <= n - mn; i += 2) cout << i << " ";
            cout << "\n";
        }
    }
    return 0;
}