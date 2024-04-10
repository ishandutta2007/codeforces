#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef unsigned long long ll;
typedef long double ld;

const int N = 3e5 + 10;
const int M = 1e7 + 1;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;

struct K {
    int l, r, num;

    bool operator < (const K a) const {
        if (a.r != r)
            return r < a.r;
        return num < a.num;
    }

} a[N];

bool cmp(K a, K b) {
    return a.l < b.l || (a.l == b.l && a.r < b.r) ||
        (a.l == b.l && a.r == b.r && a.num < b.num);
}

int main() {
    //freopen("a.in", "r", stdin);
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    fr(i, n) {
        cin >> a[i].l >> a[i].r;
        a[i].num = i + 1;
    }
    sort(a, a + n, cmp);

    int ans = 0;
    set <K> s;

    fr(i, n) {
        s.insert(a[i]);
        while (s.size() && (s.begin()->r < a[i].l))
            s.erase(s.begin());
        while (s.size() > k)
            s.erase(s.begin());
        if (s.size() == k && ans < (s.begin()->r - a[i].l + 1))
            ans = (s.begin()->r - a[i].l + 1);
    }

    s.clear();
    fr(i, n) {
        s.insert(a[i]);
        while (s.size() && (s.begin()->r < a[i].l))
            s.erase(s.begin());
        while (s.size() > k)
            s.erase(s.begin());
        if (s.size() == k && ans == (s.begin()->r - a[i].l + 1)) {
            cout << ans << endl;
            for (auto it: s)
                cout << it.num << " ";
            return 0;
        }
    }
    cout << 0 << endl;
    fr(i, k)
        cout << i + 1 << " ";

}