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
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 9;
int a[MAXN];
int b[MAXN];
int n;
bool used[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        a[x] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        b[i] = a[x];
    }
    int ans = 0;
    int pt = 0;
    for (int i = 0; i < n; i++)
    {
        if (pt < b[i])
            ans++;
        used[b[i]] = 1;
        while (pt < n && used[pt])
            pt++;
    }
    cout << ans;
}