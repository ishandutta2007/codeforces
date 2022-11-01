#include <bits/stdc++.h>
#define frab(i, a, b) for (int i = a; i < b; i++)
#define fr(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e6 + 10;
const ll INF = 2e9 + 10;
const ll N = 5e2 + 10;
const ll MOD = 1e9 + 7;

int a[N];
int d[2][N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("a.in", "r", stdin);
    int n, m, b, mod;
    cin >> n >> m >> b >> mod;
    fr(i, n)
        cin >> a[i];
    d[0][0][0] = 1;
    fr(i, n) {
        fr(er, b + 1)
            fr(cnt, m + 1)
                d[i % 2][er][cnt] = 0;
        if (!i)
            d[0][0][0] = 1;
        fr(er, b + 1)
            fr(cnt, m + 1) {
                if ((i || er || cnt) && cnt - 1 >= 0 && er - a[i] >= 0) {
                    //if (i)
                      //  d[i][er][cnt] += d[i - 1][er - a[i]][cnt - 1];
                    //if (!i || er - a[i] != 0 && cnt - 1 != 0)
                        d[i % 2][er][cnt] += d[i % 2][er - a[i]][cnt - 1];
                }
                if (i)
                    d[i % 2][er][cnt] += d[(i + 1) % 2][er][cnt];
                d[i % 2][er][cnt] %= mod;
            }
    }
//    fr(i, n)
//        fr(er, b + 1)
//            fr(cnt, m + 1)
//                cout << i << " " << er << " " << cnt << " " << d[i][er][cnt] << endl;
    int ans = 0;
    fr(i, b + 1) {
        ans += d[(n - 1) % 2][i][m];
        ans %= mod;
    }
    cout << ans;
}