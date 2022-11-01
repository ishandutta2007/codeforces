#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e3 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

int a[N][N];
bool used[N];
int ans[N];

int main() {
    int n;
    cin >> n;
    frab(i, 1, n * 2)
        fr(j, i) {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    fr(i, n) {
        int tmp = -INF, posy = -1, posx = -1;
        fr(j, n * 2)
            if (!used[j])
                fr(k, 2 * n)
                    if (!used[k] && tmp < a[j][k])
                        tmp = a[j][k], posy = k, posx = j;
        if (posy == -1) break;
        ans[posx] = posy;
        ans[posy] = posx;
        used[posx] = used[posy] = true;
    }
    fr(i, 2 * n)
        cout << ans[i] + 1 << " ";
}