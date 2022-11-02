#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 109;
int a[MAX_N];
int ma[MAX_N];
int c[MAX_N];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef ON_PC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ON_PC
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        t--;
        ma[t] = max(ma[t], a[i]);
        c[i] = t;
    }
    vector<int> u;
    for (int i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        t--;
        u.push_back(t);
    }
    int ans = 0;
    for (int i : u)
    {
        if (a[i] != ma[c[i]])
            ans++;
    }
    cout << ans;
}