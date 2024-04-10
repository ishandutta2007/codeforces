#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const ll INF = 2e9 + 1;
const int ST = 110;
const ld EPS = 1e-12;
const ld PI = acos(-1);

int a[N], b[N];
int q[ST][ST];
int ans[ST][ST];
int tst[ST][ST];

int main() {
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    fill(a, a + n, -1);
    fill(b, b + m, -1);
    fr(i, n)
        fr(j, m) {
            int t;
            cin >> q[i][j];
            if (!q[i][j]) {
                a[i] = b[j] = 0;
            }
        }
    fr(i, n)
        fr(j, m)
            ans[i][j] = ((!a[i] || !b[j]) ? 0 : 1);
    fr(i, n)
        fr(j, m) {
            tst[i][j] = ans[i][j];
            fr(k, n)
                tst[i][j] |= ans[k][j];
            fr(k, m)
                tst[i][j] |= ans[i][k];
        }
    fr(i, n)
        fr(j, m)
            if (tst[i][j] != q[i][j]) {
                cout << "NO";
                return 0;
            }
    cout << "YES" << endl;
    fr(i, n){
        fr(j, m)
            cout << ans[i][j] << " ";cout << endl;}


}