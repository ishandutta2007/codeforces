#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define ld long double
#define matr vector<vector<int> >
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e5 + 9;
int a[maxn];
int n;
int cnt[maxn];
int mask;

bool cmp(int x, int y)
{
    return (x & mask) > (y & mask);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int x = a[i];
        int e = 0;
        while (x)
        {
            if (x % 2)
                cnt[e]++;
            x /= 2;
            e++;
        }
    }
    for (int e = 0; e < maxn; e++)
    {
        if (cnt[e] == 1)
            mask |= (1ll << e);
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}