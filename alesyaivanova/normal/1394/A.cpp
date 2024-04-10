#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e5 + 9;
int a[maxn];
int b[maxn];
int pt1, pt2, n, d, m;
int pa[maxn];
int pb[maxn];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> d >> m;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        if (x <= m)
        {
            a[pt1] = x;
            pt1++;
        }
        else
        {
            b[pt2] = x;
            pt2++;
        }
    }
    if (!pt2)
    {
        cout << sum;
        return 0;
    }
    sort(a, a + pt1);
    sort(b, b + pt2);
    for (int i = 0; i < pt1; i++)
        pa[i] = (i ? pa[i - 1] : 0) + a[i];
    for (int i = 0; i < pt2; i++)
        pb[i] = (i ? pb[i - 1] : 0) + b[i];
    int ma = 0;
    for (int i = pt2 - 1; i >= 0; i--)
    {
        int pos = (pt2 - i - 1) * d - i;
        if (pos > pt1 || pos + d < 0)
            continue;
        pos = max(pos, 0ll);
        int cur = (i ? pb[i - 1] : 0) + (pos ? pa[pos - 1] : 0);
        ma = max(ma, sum - cur);
    }
    cout << ma;
}