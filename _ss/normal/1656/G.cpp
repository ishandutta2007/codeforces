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

const int N = 2e5 + 10;
vi pos[N];
int p[N];

int find_root(int u)
{
    if (p[u] > 0) return (p[u] = find_root(p[u]));
    return u;
}

void merg(int u, int v)
{
    if (p[u] > p[v]) swap(u, v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
}

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
        for (int i = 1; i <= n; ++i) pos[i].clear();
        for (int i = 1, x; i <= n; ++i) cin >> x, pos[x].eb(i);
        int cnt_odd = 0, odd;
        for (int i = 1; i <= n; ++i)
            if (pos[i].size() & 1) cnt_odd++, odd = i;
        if (cnt_odd > 1)
        {
            cout << "NO\n";
            continue;
        }
        vi a(n + 1, 0);
        if (cnt_odd == 1)
        {
            if ((int)pos[odd].size() == 1 && pos[odd][0] == (n + 1) / 2)
            {
                cout << "NO\n";
                continue;
            }
            if (pos[odd].back() == (n + 1) / 2) swap(pos[odd].back(), pos[odd][0]);
            a[(n + 1) / 2] = pos[odd].back();
            pos[odd].pop_back();
        }
        int j = 1;
        for (int i = 1; i <= n / 2; ++i)
        {
            while (pos[j].empty()) j++;
            a[i] = pos[j].back();
            pos[j].pop_back();
            a[n - i + 1] = pos[j].back();
            pos[j].pop_back();
        }
        for (int i = 1; i <= n; ++i) p[i] = 0;
        for (int i = 1; i <= n; ++i)
        {
            int ri = find_root(i);
            int rai = find_root(a[i]);
            if (ri != rai) merg(ri, rai);
        }
        for (int i = 1; i <= n / 2; ++i)
        {
            int ri = find_root(i);
            int rvi = find_root(n - i + 1);
            if (ri != rvi) merg(ri, rvi), swap(a[i], a[n - i + 1]);
        }
        for (int i = 1; i < n / 2; ++i)
        {
            int ri = find_root(i);
            int rni = find_root(i + 1);
            if (ri != rni) merg(ri, rni), swap(a[i], a[i + 1]), swap(a[n - i + 1], a[n - i]), swap(a[i + 1], a[n - i]);
        }
        cout << "YES\n";
        for (int i = 1; i <= n; ++i) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}