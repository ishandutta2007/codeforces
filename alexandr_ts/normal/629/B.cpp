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
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;

char ch[N];
int l[N], r[N];

int main() {
    //freopen("sweets.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> ch[i] >> l[i] >> r[i];
    int ans = 0;
    frab(i, 1, 367) {
        int m = 0, f = 0;
        fr(j, n)
            if (l[j] <= i && i <= r[j])
                if (ch[j] == 'M')
                    m++;
                else
                    f++;
        ans = max(ans, 2 * min(m, f));
    }
    cout << ans;

}