#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;
map <int, int> cnt;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        res += cnt[k ^ x];
        cnt[x]++;
    }
    cout << res << '\n';
}