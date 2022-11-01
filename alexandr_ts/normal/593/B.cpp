#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 1;
const ll INF = 2e9;
const ll MAX = 1e6 + 1;
const ll ALPH = 300;
const ld PI = acos(-1);
const ll MOD = 1e9 + 7;

struct ln {
    ll k, b;
    ll y1, y2;
} a[N];

bool cmp(ln a, ln b) {
    return a.y1 < b.y1 || a.y1 == b.y1 && a.y2 < b.y2;
}

int main() {
    //setlocale(LC_CTYPE,"Russian");
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    srand(time(NULL));
    cout << fixed << setprecision(12);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, x1, x2;
    cin >> n;
    cin >> x1 >> x2;
    fr(i, n) {
        cin >> a[i].k >> a[i].b;
        a[i].y1 = a[i].k * x1 + a[i].b;
        a[i].y2 = a[i].k * x2 + a[i].b;
    }
    sort(a, a + n, cmp);
    fr(i, n - 1)
        if (a[i].y2 > a[i + 1].y2) {
            cout << "YES";
            return 0;
        }
    cout << "NO";

}