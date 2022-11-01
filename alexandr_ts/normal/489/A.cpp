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

vector <pr> ans;
int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, n - 1) {
        if (i != (int)(min_element(a + i, a + n) - a))
            ans.pb(mp(i, (int)(min_element(a + i, a + n) - a)));
        swap(a[i], *min_element(a + i, a + n));
    }
//    fr(i, n)
//    cout << a[i] << " ";
    cout << ans.size() << endl;
    fr(i, ans.size())
        cout << ans[i].first << " " << ans[i].second << endl;
}