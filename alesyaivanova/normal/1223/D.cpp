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

const int MAXN = 3e5 + 9;
int a[MAXN];
int l[MAXN];
int r[MAXN];
int dp[MAXN];

void add(vector<int>& d, int i, int x)
{
    int sz = (int)d.size() / 2;
    i += sz;
    while (i)
    {
        d[i] = max(d[i], x);
        i /= 2;
    }
}

int get(vector<int>& d, int i, int l, int r, int left, int right)
{
    if (right <= l || left >= r)
        return 0;
    if (left <= l && right >= r)
        return d[i];
    return max(get(d, i * 2, l, (l + r) / 2, left, right), get(d, i * 2 + 1, (l + r) / 2, r, left, right));
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        int n;
        cin >> n;
        vector<int> x(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            x[i] = a[i];
            l[i] = -1;
            r[i] = -1;
            dp[i] = 0;
        }
        sort(x.begin(), x.end());
        x.resize(unique(x.begin(), x.end()) - x.begin());
        for (int i = 0; i < n; i++)
        {
            a[i] = lower_bound(x.begin(), x.end(), a[i]) - x.begin();
            if (l[a[i]] == -1)
                l[a[i]] = i;
            r[a[i]] = i;
        }
        int m = x.size();
//        for (int i = 0; i < m; i++)
//            cout << l[i] << " " << r[i] << "\n";
        int sz = 2;
        while (sz < m)
            sz *= 2;
        vector<int> d(2 * sz, 0);
        int ma = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == l[a[i]])
            {
                int cur = (a[i] ? get(d, 1, 0, sz, a[i] - 1, a[i]) : 0);
                dp[r[a[i]]] = cur + 1;
                ma = max(ma, cur + 1);
            }
            if (i == r[a[i]])
                add(d, a[i], dp[i]);
            //cout << dp[i] << " ";
        }
        //cout << "\n";
        cout << m - ma << "\n";
    }
}