#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        set<int> st;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            st.insert(x);
        }
        int flag = 0;
        for (int i : st)
            if (st.find(i + k) != st.end())
                flag = 1;
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}