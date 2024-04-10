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
typedef pair <int, int> pr;

const ll N = 1e6 + 10;
const ld EPS = 1e-13;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

ll lft[N], a[N], rgt[N], qua[N];

int main() {
    //ld st1 = clock();
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    fill(lft, lft + N, INF);
    fill(rgt, rgt + N, -INF);
    fr(i, n) {
        cin >> a[i];
        qua[a[i]]++;
        lft[a[i]] = min(lft[a[i]], (ll)i);
        rgt[a[i]] = max(rgt[a[i]], (ll)i);
    }
    int ans = INF;
    int ansl, ansr;
    int x = *max_element(qua, qua + N);
    fr(i, N)
        if (qua[i] == x)
        if (ans > rgt[i] - lft[i] + 1) {
            ans = rgt[i] - lft[i] + 1;
            ansl = lft[i];
            ansr = rgt[i];
        }
    cout << ansl + 1 << " " << ansr + 1 << endl;
}