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
        int n;
        cin >> n;
        set<int> st;
        while (n--) {
            int x;
            cin >> x;
            if (st.find(x) != st.end())
                st.insert(-x);
            else
                st.insert(x);
        }
        cout << SZ(st) << "\n";
    }
}