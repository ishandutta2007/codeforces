#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define SSTR(x) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e3 + 10;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

bool a[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    int x, n, cur = 1, l, r, ans = 0;
    cin >> n >> x;
    fr(i, n) {
        cin >> l >> r;
        while (cur + x <= l)
            cur += x;
        while (cur < l)
            cur++, ans++;
        ans += r - l + 1;
        cur = r + 1;
    }
    cout << ans;

}