#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 1e6 + 10;

pair<int, int> a[N];
int ans[N];

void solve() {
    int n;
    scanf("%d", &n);
    fr(i, n) {
        scanf("%d", &a[i].first);
        a[i].first = n - 1 - a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    int cur = 1;
    fr(i, n) {
        int cnt = a[i].first;
        ans[a[i].second] = cur;
        fr(j, cnt) {
            i++;
            ans[a[i].second] = cur;
        }

        cur++;
    }

    map<int, int> m;
    fr(i, n)
        m[ans[i]]++;
    fr(i, n)
        if (a[i].first + 1 != m[ans[a[i].second]]) {
            cout << "Impossible";
            return;
        }

    cout << "Possible" << endl;
    fr(i, n)
        cout << ans[i] << " ";


}

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    solve();

    return 0;
}