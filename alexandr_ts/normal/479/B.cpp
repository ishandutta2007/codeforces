#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e2 + 1;
const ll INF = 3e18;
const ll MAX = 1e6 + 1;
const ll ALPH = 300;
const ld EPS = 1e-12;
const ll MOD = 1e9 + 7;

struct tmp {
    int x, pos;
} a[N];

bool cmp(tmp a, tmp b) {
    return a.x < b.x;
}

int main() {
    int n, k;
    cin >> n >> k;
    fr(i, n) {
        cin >> a[i].x;
        a[i].pos = i + 1;
    }
    vector <pr> ans;
    sort(a, a + n, cmp);
    fr(i, k) {
        if (a[0].x < a[n - 1].x) {
            a[0].x++, a[n - 1].x--;
            ans.pb(mp(a[0].pos, a[n - 1].pos));
        }
        stable_sort(a, a + n, cmp);
    }
    cout << a[n - 1].x - a[0].x << " " << ans.size() << endl;
    fr(i, ans.size())
        cout << ans[i].second << " " << ans[i].first << endl;
}