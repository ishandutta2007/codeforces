#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

ll MOD = (ll) 10939;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 1e17;
const ll LOG = 20;
int n, a[MAXN], q, x, y;
int last[LOG];
int dp[MAXN][LOG];

int main() {

    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];

    memset(last, -1, sizeof last);

    for (int i = n-1; i >= 0; i--) {
        fill(dp[i], dp[i]+LOG, n);

        for (int bit = 0; bit < LOG; bit++)
        {
            if ((a[i]>>bit)&1)
            {
                if (last[bit] != -1 ) {

                    int idx = last[bit];

                    for (int bt = 0; bt < LOG; bt++)
                        dp[i][bt] = min(dp[i][bt], dp[idx][bt]);
                }
                last[bit] = i;
                dp[i][bit] = i;
            }
        }
    }

    while (q--) {
        cin >> x >> y;
        x--, y--;

        bool found = false;
        for (int bit = 0; bit < LOG; bit++)
            if ((a[y]>>bit)&1) {
                if (dp[x][bit] <= y) {
                    found = true;
                    break;
                }
            }

        if (found)  cout << "Shi" << endl;
        else cout << "Fou" << endl;
    }

    return 0;
}