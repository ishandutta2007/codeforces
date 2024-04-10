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
int r[N][6], n;

bool cmp(int x, int y)
{
    int cnt = 0;
    for (int j = 1; j <= 5; ++j)
        if (r[x][j] < r[y][j]) cnt++;
    return (cnt >= 3);
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
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= 5; ++j) cin >> r[i][j];
        int best = 1;
        for (int i = 2; i <= n; ++i)
            if (cmp(i, best)) best = i;
        bool check = true;
        for (int i = 1; i <= n; ++i)
            if (i != best && cmp(i, best)) check = false;
        if (!check) best = -1;
        cout << best << "\n";
    }
    return 0;
}