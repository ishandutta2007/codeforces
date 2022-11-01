#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define SSTR(x) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const ll N = 1e5 + 1;
const ll M = 2e6;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9 + 1;
const ll MOD = 1e9 + 7;

int a[N], b[N], c[N];
//vector <pr> ans;

pr ans[M + 1];
int lastel = 0;

int main() {
    //ld st = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, tmp;
    cin >> n;
    frab(i, 1, 1 + n) {
        cin >> a[i];
    }
    frab(i,1, 1 + n) {
        cin >> b[i];
        c[b[i]] = i;
    }
    frab(i, 1, 1 + n)
        a[i] = c[a[i]];
    //frab(j, 1, n + 1)
                   // cout << a[j] << " ";cout << endl;

    int answ = 0;

    for (int i = 1; i <= n; i++) {
        int cur = min_element(a + i, a + n + 1) - a;
        for (int j = cur - 1; j >= i; j--)
            if (a[j] >= cur) {
                answ += abs(j - cur);
                //ans.pb(mp(j, cur));
                ans[lastel++] = mp(j, cur);
                swap(a[j], a[cur]);
                cur = j;
                //frab(j, 1, n + 1)
                   // cout << a[j] << " ";cout << endl;
            }
    }
    cout << answ << endl;
    cout << lastel << endl;
    fr(i, lastel)
        printf("%d %d\n", ans[i].first, ans[i].second);//cout << ans[i].first << " " << ans[i].second << endl;
    //cout << clock() - st;
//    freopen("input.txt", "w", stdout);
//    cout << 2000;
//    int a[2000];
//    fr(i, 2000)
//        a[i] = i + 1;
//    random_shuffle(a, a + 2000);
//    fr(i, 2000)
//        cout << a[i] << " ";cout << endl;
//    random_shuffle(a, a + 2000);
//    fr(i, 2000)
//        cout << a[i] << " ";cout << endl;
}