#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 2e5 + 10;
const ll M = 1e6 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    //srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    fr(i, n)
        cin >> a[i];
    set <int> st;
    fr(i, m) {
        int typ, x;
        cin >> typ >> x;
        if (typ == 1)
            st.insert(a[x - 1]);
        while (st.size() > k)
            st.erase(st.begin());
        if (typ == 2)
            if (st.count(a[x - 1]))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
    }
}