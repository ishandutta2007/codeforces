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
        vi mx(11, 0);
        cin >> n;
        for (int i = 1, x, y; i <= n; ++i) cin >> x >> y, mx[y] = max(mx[y], x);
        bool check = true;
        int sum = 0;
        for (int i = 1; i <= 10; ++i)
            if (mx[i] == 0) check = false;
            else sum += mx[i];
        if (check) cout << sum << "\n";
        else cout << "MOREPROBLEMS\n";
    }
    return 0;
}