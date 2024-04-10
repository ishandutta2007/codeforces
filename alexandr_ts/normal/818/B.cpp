#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;
const int N = 1e6 + 2;

int a[N], l[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fr(i, m)
        cin >> l[i];
    map <int, int> m1;

    fr(i, m - 1) {
        int t1 = l[i], t2 = l[i + 1];
        if (t2 <= t1) t2 += n;
        if (a[t1] && a[t1] != t2 - t1) {
            cout << -1;
            return 0;
        }
        else {
            a[t1] = t2 - t1;
            if (m1.count(t2 - t1) && m1[t2 - t1] != t1) {
                cout << -1;
                return 0;
            }
            m1[t2 - t1] = t1;
        }
    }

    set <int> st;
    frab(i, 1, n + 1)
        st.insert(a[i]);
    int cur = 1;

    frab(i, 1, n + 1) {
        if (a[i] == 0) {
            while (st.count(cur))
                cur++;
            a[i] = cur;
            cur++;
        }
        cout << a[i] << " ";
    }
}