#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ld long double
#define pb emplace_back
#define pii pair<int, int>

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<char, int>> a(2 * n);
    vector<pii> pos;
    vector<int> del(n + 1);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i].fi;
        if (a[i].fi == '-') {
            cin >> a[i].se;
            pos.pb(i, a[i].se);
            del[a[i].se] = i;
        }
    }
    vector<vector<int>> add(2 * n);
    stack<pii> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && pos[i].se > st.top().se) {
            add[pos[i].fi].pb(st.top().se);
            st.pop();
        }
        st.push(pos[i]);
    }
    set<pii> s;
    while (st.size()) {
        s.insert({del[st.top().se], st.top().se});
        st.pop();
    }
    vector<int> ans;
    set<int> kek;
    for (int i = 0; i < 2 * n; i++) {
        if (a[i].fi == '+' && (int)s.size() == 0) {
            cout << "NO";
            return 0;
        }
        if (a[i].fi == '+') {
            ans.pb(s.begin()->se);
            s.erase(s.begin());
            kek.insert(ans.back());
        } else {
            if (kek.find(a[i].se) == kek.end()) {
                cout << "NO";
                return 0;
            }
        }
        for (auto &c : add[i]) {
            s.insert({del[c], c});
        }
    }
    cout << "YES\n";
    for (auto &c : ans) cout << c << " ";
    return 0;
}