#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 2e5 + 10;

int a[N];

ll solve(ll n, ll x) {

    if (x % 2)
        return (x + 1) / 2;
    if (n % 2 == 0) {
        return solve(n / 2, x / 2) + n / 2;
    }
    else
        return solve(n / 2 + 1, x / 2 + 1) + n / 2;
}

int main() {
    //freopen("a.in", "r", stdin);
//    int n;
//
//    scanf("%d", &n);
    ios_base::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    ll x;
    for (int i = 0; i < q; i++) {
        cin >> x;
        cout << solve(n, x) << "\n";
    }
//    for (int n = 4; n <= 100; n++) {
//        fill(a, a + n * 2 + 1, 0);
//        for (int i = 1; i <= n; i++)
//            a[2 * i - 1] = i;
//        while (true) {
//            int pos = -1;
//            for (int i = 2 * n - 1; i >= 1; i--) {
//                if (a[i] != 0) {
//                    pos = i;
//                    break;
//                }
//            }
//            int newpos = -1;
//            for (int i = pos; i >= 1; i--)
//                if (a[i] == 0) {
//                    newpos = i;
//                    break;
//                }
//            if (newpos == -1) break;
//            swap(a[pos], a[newpos]);
//        }
//        //cout << n << ": ";
////        if (n % 2) {
////            for (int i = 2; i + 2 <= n; i += 4)
////                swap(a[i], a[i + 2]);
////        }
////        for (int i = 1; i <= n; i += 1)
////            cout << a[i] << " ";
////        cout << endl;
//        for (int i = 1; i <= n; i++)
//        if (solve(n, i) != a[i]) {
//            cout << "Error\n";
//            cout << n;
//        }
//    }
//    cout << "40: ";
//    for (int i = 1; i <= 40; i++)
//        cout << solve(40, i) << " ";cout << endl;
}