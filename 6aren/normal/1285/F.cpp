#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 100005;

vector<int> divs[N];
vector<int> mult[N];

int mu[N], a[N], n;
int cnt[N];
long long res = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    mu[1] = 1;
    for (int i = 1; i < N; i++) {
        divs[i].pb(i);
        for (int j = 2 * i; j < N; j += i) {
            divs[j].pb(i);
            mu[j] -= mu[i]; 
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int e : divs[a[i]]) mult[e].pb(a[i] / e);
    }
    for (int i = 1; i < N; i++) {
        sort(all(mult[i]), [](int x, int y) {
            return x > y;
        });
        stack<int> st;
        for (int e : mult[i]) {
            int ans = 0;
            for (int div : divs[e]) {
                ans -= mu[div] * cnt[div];
            }
            bool ok = 0;
            while (ans != 0) {
                int u = st.top();
                st.pop();
                for (int div : divs[u]) {
                    cnt[div]--;
                    if (e % div == 0) ans += mu[div];
                }
                if (ans == 0) res = max(res, 1LL * i * e * u);
                if (st.empty()) {
                    ok = 1;
                    break;
                } 
            }
            if (ok) break;
            st.push(e);
            for (int div : divs[e]) cnt[div]++;
        }
        for (int e : mult[i]) {
            for (int div : divs[e]) cnt[div] = 0;
        }
    }
    cout << res;
    return 0;
}