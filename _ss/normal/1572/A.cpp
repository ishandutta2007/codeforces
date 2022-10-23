#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 2e5 + 10;
vi G[N];
int in[N], n;

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
        for (int i = 1; i <= n; ++i) G[i].clear();
        priority_queue<int, vi, greater<int>> q[2];
        for (int i = 1; i <= n; ++i)
        {
            cin >> in[i];
            for (int j = 1, x; j <= in[i]; ++j)
            {
                cin >> x;
                G[x].eb(i);
            }
            if (in[i] == 0) q[1].push(i);
        }
        int cnt = 0, last = 0;
        for (int i = 1; i <= n && !q[i & 1].empty(); ++i)
            while (!q[i & 1].empty())
            {
                int u = q[i & 1].top();
                q[i & 1].pop();
                cnt++;
                last = i;
                for (int v : G[u])
                {
                    in[v]--;
                    if (in[v] == 0)
                    {
                        if (v > u) q[i & 1].push(v);
                        else q[(i & 1) ^ 1].push(v);
                    }
                }
            }
        if (cnt == n) cout << last << "\n";
        else cout << "-1\n";

    }
    return 0;
}