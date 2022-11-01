#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < (ll)n; i++)
#define frab(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

using namespace std;

typedef long long ll;

const ll N = 1e6 + 10;
const ll INF = 2e9;
const ll ALPH = 300;

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("a.in", "r", stdin);
    ll n, k, a, m;
    set <int> st, st2;
    cin >> n >> k >> a;
    st.insert(0), st.insert(n + 1);
    st2.insert(n);
    cin >> m;
    int cnt = (n + 1) / (a + 1);
    if (cnt < k) {
        cout << -1;
        return 0;
    }
    fr(i, m) {
        int t;
        cin >> t;
        int l = *(--st.lower_bound(t));
        int r = *st.upper_bound(t);
        //cout << l << " " << r << endl;
        st.insert(t);
//        st2.erase(r - l + 1);
//        st2.insert(t - l);
//        st2.insert(r - t);
        cnt -= (r - l) / (a + 1);
        cnt += (t - l) / (a + 1) + (r - t) / (1 + a);
        if (cnt < k) {
            cout << i + 1;
            return 0;
        }
       // cout << cnt << endl;
    }
    cout << -1;
}