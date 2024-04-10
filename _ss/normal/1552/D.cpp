#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e5 + 10;
int n, a[N], check;

void dfs(int id, int sum, int cnt)
{
    if (id > n)
    {
        if (sum == 0 && cnt > 0) check = 1;
        return;
    }
    dfs(id + 1, sum, cnt);
    dfs(id + 1, sum - a[id], cnt + 1);
    dfs(id + 1, sum + a[id], cnt + 1);
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
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i], a[i] = abs(a[i]);
        check = 0;
        dfs(1, 0, 0);
        if (check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}