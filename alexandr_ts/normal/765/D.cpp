#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5 + 10;
const ll INF = 2e12 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

int f[N], q[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    frab(i, 1, 1 + n)
        cin >> f[i];
    set <int> st;
    map <int, int> q;
    frab(i, 1, 1 + n) {
        st.insert(f[i]);
        if (f[f[i]] != f[i]) {
            cout << -1;
            return 0;
        }
    }
    int cnt = 0;
    for (auto it: st)
        q[it] = ++cnt;
    cout << cnt << endl;
    frab(i, 1, 1 + n)
        cout << q[f[i]] << " ";
    cout << endl;
    for (auto it: st)
        cout << it << " ";
}