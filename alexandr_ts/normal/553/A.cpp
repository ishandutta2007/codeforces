#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e3 + 2;
const ld EPS = 1e-8;

ll ans[N], a[N];
ll c[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> k;
    fr(i, k)
        cin >> a[i];
    fr(i, N)
        fr(j, N)
            if (i >= j)
                if (i > 0 && j > 0)
                    c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
                else if (j == 0)
                    c[i][j] = 1;
    n = accumulate(a, a + k, 0);
    ans[0] = 1;
    frab(i, 1, k) {
        ll total = accumulate(a, a + i, 0) + a[i] - 1;
        ans[i] = ans[i - 1] * c[total][a[i] - 1] % MOD;
        //out << total << " " << a[i] - 1 << " " << c[total][a[i] - 1] << endl;
    }
    cout << ans[k - 1];
}