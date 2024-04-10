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

const ll N = 1e6 + 10;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

bool a[N];

char b[N];
int ar[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    int n, t, ans = 0, cur = 0;
    cin >> n;
    char ch;
    fr(i, n) {
        cin >> ch >> ar[i];
        if (ch == '+')
            b[i] = true;
        bool nw;
        if (ch == '+')
            nw = true;
        else
            nw = false;
        cur += nw - a[ar[i]];
        a[ar[i]] = nw;
        ans = max(ans, cur);
    }
    ans = max(ans, cur);//cout << cur;
    for (int i = n - 1; i >= 0; i--) {
        bool nw;
        if (!b[i])
            nw = true;
        else
            nw = false;
        cur += nw - a[ar[i]];
        a[ar[i]] = nw;
        ans = max(ans, cur);
    }
    cout << ans;
}