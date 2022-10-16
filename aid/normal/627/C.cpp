#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXM = 200 * 1000 + 5;
const long long INF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 5;
pair<int, int> pp[MAXM];
int x[MAXM], p[MAXM], nxt[MAXM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int d, n, m;
    cin >> d >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> pp[i].first >> pp[i].second;
    pp[m] = make_pair(0, 0);
    m++;
    pp[m] = make_pair(d, 0);
    m++;
    sort(pp, pp + m);
    for(int i = 0; i < m; i++) {
        x[i] = pp[i].first;
        p[i] = pp[i].second;
    }
    for(int i = 0; i + 1 < m; i++)
        if(x[i] + n < x[i + 1]) {
            cout << -1 << '\n';
            return 0;
        }
    vector<int> st;
    for(int i = m - 1; i >= 0; i--) {
        while(!st.empty() && p[i] < p[st.back()])
            st.pop_back();
        if(!st.empty())
            nxt[i] = st.back();
        st.push_back(i);
    }
    int cur = n;
    long long ans = 0;
    for(int i = 0; i + 1 < m;) {
        if(x[i] + n >= x[nxt[i]]) {
            if(cur < x[nxt[i]] - x[i]) {
                ans += (long long)p[i] * (x[nxt[i]] - x[i] - cur);
                cur = x[nxt[i]] - x[i];
            }
            cur -= x[nxt[i]] - x[i];
            i = nxt[i];
            continue;
        }
        ans += (long long)p[i] * (n - cur);
        cur = n - (x[i + 1] - x[i]);
        i++;
    }
    cout << ans << '\n';
    return 0;
}