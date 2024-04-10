#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 300ll;
const ll MOD = 1000000007ll;
const ll P = 259ll;

ll a[N][N];
bool an[N];
bool am[N];
vector <int> np;

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int a = 0; a <= n; a++)
        for (int b = 0; b <= n; b++)
            if (a * a + b == n && a + b * b == m)
                ans++;
    cout << ans;

}