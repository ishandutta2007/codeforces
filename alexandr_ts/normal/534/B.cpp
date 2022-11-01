#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 1;
const ll INF = 2e9;
const ll MAX = 1e6 + 1;
const ll ALPH = 300;
const ld PI = acos(-1);
const ll MOD = 1e9 + 7;

int dp[101][10001];

int main() {
    //setlocale(LC_CTYPE,"Russian");
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    srand(time(NULL));
    cout << fixed << setprecision(12);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;
    dp[0][v1] = v1;
    fr(i, t)
        fr(j, 10001)
            if (dp[i][j])
                for (int k = -d; k <= d; k++)
                    if (j + k >= 0)
                        dp[i + 1][j + k] = max((ll)dp[i + 1][j + k], dp[i][j] + j + k);
    cout << dp[t - 1][v2];

}