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
int a[N], n, b[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) pos[i].clear();
        for (int i = 1; i <= n; ++i) cin >> a[i], pos[a[i]].eb(i);
        int mx = 1;
        for (int i = 1; i <= n; ++i)
            if (pos[i].size() > pos[mx].size()) mx = i;
        queue<int> q;
        for (int i = 1; i <= (int)pos[mx].size(); ++i) q.push(mx);
        for (int i = 1; i <= n; ++i)
        {
            int j = (mx + i - 1) % n + 1;
            for (int p : pos[j])
            {
                b[p] = q.front();
                q.pop();
            }
            for (int d = 1; d <= (int)pos[j].size(); ++d) q.push(j);
        }
        for (int i = 1; i <= n; ++i) cout << b[i] << " ";
        cout << "\n";
    }
    return 0;
}