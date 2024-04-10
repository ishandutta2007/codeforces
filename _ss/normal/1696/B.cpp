#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

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
        for (int i = 1; i <= n; ++i) cin >> a[i];
        a[n + 1] = 0;
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (a[i - 1] == 0 && a[i] > 0) cnt++;
        cout << min(cnt, 2) << "\n";
    }
    return 0;
}