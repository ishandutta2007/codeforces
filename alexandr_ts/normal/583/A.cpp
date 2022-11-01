#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define SSTR(x) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const ll N = 1e5 + 10;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9 + 1;
const ll MOD = 1e9 + 7;

bool used1[N], used2[N];

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector <int> ans;
    int x, y;
    fr(i, n * n) {
        cin >>x >> y;
        if (!used1[x] && !used2[y]) {
            ans.pb(i + 1);
            used1[x] = used2[y] = true;
        }
    }
    fr(i, ans.size())
        cout << ans[i] << " ";
}