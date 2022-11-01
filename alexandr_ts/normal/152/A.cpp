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

const ll N = 1e3 + 10;
const ld EPS = 1e-13;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

char a[N][N];
bool g[N];

int main() {
    //ld st1 = clock();
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    //fill(g, g + n, true);
    fr(i, n)
        fr(j, m)
            cin >> a[i][j];
    int q = 0;
    fr(i, n) {
        fr(j, m) {
            bool b = false;
            fr(k, n)
                if (a[i][j] < a[k][j])
                    b = true;
            if (!b)
                g[i] = true;
        }
    }
    cout << accumulate(g, g + n, 0);
}