#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ll P = 29;
const ld EPS = 1e-9;

const int N = 1e3 + 10;

int a[N][N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    if (k > n * n)
        cout << -1;
    else {
//        if (k % 2 == n % 2) {
//            fr(i, min(k, n))
//                a[i][i] = 1;
//            k -= min(k, n);
//        }
//        else {
//            fr(i, min(k, n - 1))
//                a[i][i] = 1;
//            k -= min(k, n - 1);
//        }
//        fr(i, n)
//            frab(j, i + 1, n)
//                if (k)
//                    a[i][j] = a[j][i] = 1, k -= 2;
        fr(i, n)
            frab(j, i, n) {
                if (k >= 2) {
                    a[i][j] = a[j][i] = 1;
                    if (i == j) k--;
                    else
                        k -= 2;
                }
                else if (k == 1) {
                    if (i == j)
                        a[i][j] = 1, k--;
                }
                else break;
            }

    fr(i, n) {
    fr(j, n)
        cout << a[i][j] << " ";cout << endl;}
    }
}