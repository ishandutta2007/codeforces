#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 100005;

int n;
int cnt[N], a[N], pos[N];
int nx[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) cnt[i] = 1;
    multiset<int> ms;
    for (int i = 1; i <= n; i++) ms.insert(-cnt[i]);
    bool ok = 1;
    stack<int> st;
    st.push(n + 1);
    a[n + 1] = n + 1;
    for (int i = n; i >= 1; i--) {
        while (a[i] > a[st.top()]) st.pop();
        nx[i] = st.top();
        st.push(i);
    }
    for (int i = 1; i <= n; i++) {
        int t = pos[i];
        int mx = *ms.begin();
        if (-cnt[t] != mx) {
            ok = 0;
            break;
        }
        auto it = ms.lower_bound(-cnt[t]);
        ms.erase(it);
        int foo = cnt[t];
        int id = nx[t];
        if (id == n + 1) continue;
        it = ms.lower_bound(-cnt[id]);
        cnt[id] += foo;
        ms.insert(-cnt[id]);
    }
    cout << (ok ? "Yes" : "No") << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        solve();
    }
    return 0;
}