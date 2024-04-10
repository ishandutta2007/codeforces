#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1073741824;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-6;

ll a[N], add[N], divs[N];

int cntDivs(int x) {
    if (divs[x] != 0)
        return divs[x];

    frab(i, 2, sqrt(x) + 1)
        if (x % i == 0 && i < x) {
            int cnt = 1, tmp = x / i;
            while (tmp % i == 0) tmp /= i, cnt++;
            divs[x] = (cnt + 1) * divs[tmp];
            return divs[x];
        }

    divs[x] = 2;
    return divs[x];
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cout << fixed << setprecision(8);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    divs[1] = 1;
    int a, b, c, ans = 0;
    cin >> a >> b >> c;
    frab(i, 1, a + 1)
        frab(j, 1, b + 1)
            frab(k, 1, c + 1)
                ans = (ans + cntDivs(i * j * k)) % MOD;
    cout << ans;
}