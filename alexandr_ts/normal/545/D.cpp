#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const ll N = 1e5 + 1;
const ll M = 2 * 1e3 + 1;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int n, t;
    cin >> n;
    multiset <int> st;
    fr(i, n) {
        cin >> t;
        st.insert(t);
    }
    vector <int> ans;
    ans.pb(*st.begin());
    st.erase(st.begin());
    int q = ans[0];
    auto it = lower_bound(st.begin(), st.end(), q);
    while (it != st.end()) {
        ans.pb(*it);
        q += *it;
        st.erase(it);
        it = lower_bound(st.begin(), st.end(), q);
    }
    cout << ans.size();
 }