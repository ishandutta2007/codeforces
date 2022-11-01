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
    char tmp;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> tmp;
            if (tmp == 'S')
                an[i] = am[j] = true;
        }
    ll ans = n * m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (an[i] && am[j])
                ans--;
    cout << ans;

}