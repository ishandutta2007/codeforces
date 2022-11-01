#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 3e5 + 50;
const ll M = 1e6 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;

ll a[N];
ll sum[N];

int main() {
    //freopen("a.in", "r", stdin);
    //srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    fr(i, n + 1) {
        cin >> a[i];
        ll fl = 1;
        if (a[i] < 0)
            fl = -1;
        if (a[i] == 0)
            continue;
        fr(j, 31ll)
            if ((fl * a[i]) & (1ll << j))
                sum[i + j] += fl;
    }
    fr(i, N)
        if (abs(sum[i]) >= 2) {
            sum[i + 1] += sum[i] / 2;
            sum[i] %= 2;
        }
    ll fl = 1;
    for (ll j = N - 1; j >= 0; j--)
        if (sum[j] != 0) {
            if (sum[j] < 0)
                fl = -1;
            else
                fl = 1;
            break;
        }
    if (fl == -1)
        fr(i, N)
            sum[i] *= -1;

    fr(i, N) {
        if (abs(sum[i]) >= 2) {
            sum[i + 1] += sum[i] / 2;
            sum[i] %= 2;
        }
        if (sum[i] == -1) {
            sum[i + 1]--;
            sum[i] = 1;
        }
    }


    ll pw = 0;
    fr(i, N)
        if (sum[i] == 0)
            pw++;
        else
            break;
    for (ll i = N - 1; i >= pw; i--) {
        if (sum[i] && i - pw > 35) {
            cout << 0;
            return 0;
        }
    }
    ll k1 = 0;
    for (ll i = N - 1; i >= pw; i--) {
        if (sum[i])
            k1 += (1ll << (i - pw));
    }
    //cout << pw << " " << k1 << " " << fl << endl;

    ll ans = 0;
    fr(i, N) {
        //cout << pw << " " << k1 << " " << fl <<  endl;
        if (pw >= 0 && pw <= n)
            if (!(a[n] == k1 * fl && pw == n))
                if (a[pw] - k1 * fl >= -k && a[pw] - k1 * fl <= k) {
                    ans++;
            }
        pw--, k1 *= 2;
        if (pw < 0 || k1 > k * k + 1)
            break;
    }
    cout << ans;


}