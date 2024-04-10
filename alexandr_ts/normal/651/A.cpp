#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e4 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e2 + 10;
const ll MOD = 1e9 + 7;

bool d[N][N];

int main() {
    //freopen("sweets.in", "r", stdin);
    int a, b;
    cin >> a >> b;
    d[a][b] = true;
    for (int cnt = a + b; cnt >= 0; cnt--)
        for (int i = a + b; i >= 1; i--)
            for (int j = cnt - i; j >= cnt - i; j--)
                if (j > 0 && i > 0)
                    if (d[i][j]) {
                        //cout << i << " " << j << " :  " << endl;
                        if (i >= 2 && j >= 0) {
                            d[i - 2][j + 1] = true;
                           // cout << i - 2 << " " << j + 1 << endl;
                        }
                        if (j >= 2 && i >= 0) {
                            d[i + 1][j - 2] = true;
                            //cout << i + 1 << " " << j - 2 << endl;
                        }
                    }
    ll ans = INF;
    fr(i, a + b + 1)
        fr(j, b + a + 1)
            if (d[i][j])
                ans = min(ans, i + j);
    cout << a + b - ans;

}