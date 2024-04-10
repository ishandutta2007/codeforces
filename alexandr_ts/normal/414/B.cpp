#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e3 + 10;
const ll INF = 2e9;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

int a[N][N];
vector <int> divs[N];

int main() {

        //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    int n, k;
    cin >> n >> k;
    ld st = clock();
    frab(i, 1, n + 1)
        frab(j, 1, sqrt(i) + 1)
            if (i % j == 0)
                if (j == i / j)
                    divs[i].pb(j);
                else if (j < i / j)
                    divs[i].pb(j), divs[i].pb(i / j);
    a[0][1] = 1;
    frab(j, 1, 1 + k)
        frab(i, 1, 1 + n)
            fr(k1, divs[i].size())
                a[j][i] = (a[j][i] + a[j - 1][divs[i][k1]]) % MOD;

    ll ans = 0;
    frab(i, 1, n + 1)
        ans = (ans + a[k][i]) % MOD;
    cout << ans;
    //cout << endl << fixed << setprecision(2) << clock() - st;
}