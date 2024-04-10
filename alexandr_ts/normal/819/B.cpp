#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;
const int N = 1e6 + 10;

ll a[N];
ll d[4 * N];


int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int n;
    scanf("%d", &n);
    //a[0] = INF;
    frab(i, 1, 1 + n)
        scanf("%I64d", &a[i]);

    ll s1 = 0, n1 = 0, s2 = 0, n2 = 0;

    ll ans = INF, ans2 = -1;

    int zero = 2 * N;

    frab(i, 1, 1 + n) {
        d[2 * N + a[i] - i]++;
        if (a[i] - i > 0)
            n2++, s2 += a[i] - i;
        else if (a[i] - i < 0)
            n1++, s1 += i - a[i];
    }

    ans = s1 + s2, ans2 = n;

    frab(i, 2, 1 + n) {
        s1 -= n1;
        s2 += (n2 + d[zero]);
        n1 -= d[zero - 1];
        n2 += d[zero];
        zero--;

        n2--, s2 -= a[i - 1];
        d[zero + a[i - 1]]--;
        if (a[i - 1] != n)
            n1++, s1 += (n - a[i - 1]);
        d[zero - n + a[i - 1]]++;

        if (s1 + s2 < ans)
            ans = s1 + s2, ans2 = i - 1;
    }

    cout << ans << " " << n - ans2;
}