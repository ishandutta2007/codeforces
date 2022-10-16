#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

const int MAXN = 300 * 1000 + 5;
vector<int> g[MAXN];

int solve(int n) {
    set<int> st;
    for(int i = 0; i < n; i++)
        st.insert(i);
    int res = 0;
    while(!st.empty()) {
        res++;
        int s = *st.begin();
        st.erase(st.begin());
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            set<int>::iterator it = st.begin();
            for(size_t i = 0; i < g[v].size(); i++) {
                int u = g[v][i];
                while(it != st.end() && *it < u) {
                    q.push(*it);
                    set<int>::iterator del = it;
                    it++;
                    st.erase(del);
                }
                if(it != st.end() && *it == u)
                    it++;
            }
            while(it != st.end()) {
                q.push(*it);
                set<int>::iterator del = it;
                it++;
                st.erase(del);
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v -= 2;
        if(v == -1)
            v = n - 1;
        u -= 2;
        if(u == -1)
            u = n - 1;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for(int i = 0; i < n; i++)
        sort(g[i].begin(), g[i].end());
    if(solve(n) != 1) {
        cout << "impossible\n";
        return 0;
    }
    for(int i = 0; i < n - 1; i++)
        while(!g[i].empty() && g[i].back() == n - 1)
            g[i].pop_back();
    int deg = n - 1 - (int)g[n - 1].size();
    if(solve(n - 1) <= k && k <= deg)
        cout << "possible\n";
    else
        cout << "impossible\n";
    return 0;
}