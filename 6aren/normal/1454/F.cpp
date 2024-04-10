#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;

int n;
int a[N], pref[N], suff[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);

    int ntest;
    cin >> ntest;

    while (ntest--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) {
            pref[i] = max(a[i], pref[i - 1]);
        }
        
        for (int i = n; i >= 1; i--) {
            suff[i] = max(a[i], suff[i + 1]);
        }

        vector<ii> st;

        vector<int> ans;
        
        for (int i = 1; i <= n; i++) {

            while (!st.empty() && st.back().x > a[i]) st.pop_back();
            st.push_back({a[i], i});
            if (i == 1 || i == n) continue;
            int l = lower_bound(pref + 1, pref + i + 1, suff[i + 1]) - pref;
            int r = lower_bound(pref + 1, pref + i + 1, suff[i + 1] + 1) - pref;
            int ll = lower_bound(st.begin(), st.end(), ii(suff[i + 1], 0)) - st.begin() - 1;
            int rr = lower_bound(st.begin(), st.end(), ii(suff[i + 1] + 1, 0)) - st.begin() - 1;
            if (ll == -1) ll = 1;
            else ll = st[ll].y + 1;
            if (rr == -1) rr = 1;
            else rr = st[rr].y + 1;

            r--;
            ll--;
            rr -= 2;

            // if (i == 7) cout << l << ' ' << r << ' ' << ll << ' ' << rr << endl;

            int u = min(r, rr);
            int v = max(l, ll);
            if (u >= v && u > 0) {
                ans = {u, i - u, n - i};
                break;
            }
        }

        cout << (ans.size() ? "YES\n" : "NO\n");
        if (ans.size()) {
            for (int e : ans) cout << e << " ";
            cout << '\n';
        }

        for (int i = 1; i <= n; i++) {
            a[i] = pref[i] = suff[i] = 0;
        }
        
    }

    return 0;
}