#include <bits/stdc++.h>

using namespace std;

vector < int > g[500005];
int nxt[500005];
int now[500005];
int a[500005];
int tmp;

void dfs(int pos){
    a[pos] = tmp--;
    for (auto key : g[pos]) dfs(key);
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    bool flag;
    cin >> T;
    for (int i = 1; i <= T; ++i){
        int n;
        cin >> n;
        for (int j = 1; j <= n + 1; ++j){
            g[j].clear();
        }
        for (int j = 1; j <= n; ++j){
            cin >> nxt[j];
            if (nxt[j] == -1) g[j + 1].push_back(j);
            else g[nxt[j]].push_back(j);
        }
        for (int j = 1; j <= n; ++j) sort(g[j].begin(), g[j].end());
        tmp = n + 1;
        dfs(n + 1);
        vector < int > st;
        flag = true;
        for (int j = n; j >= 1; --j){
            while ((int)st.size() > 0 && a[st.back()] < a[j]) st.pop_back();
            if ((int)st.size() == 0) now[j] = n + 1;
            else now[j] = st.back();
            st.push_back(j);
        }
        for (int j = 1; j <= n; ++j){
            if (nxt[j] == -1) continue;
            if (nxt[j] != now[j]) flag = false;
        }
        if (flag){
            for (int j = 1; j <= n; ++j) cout << a[j] << " ";
            cout << '\n';
        }
        else cout << -1 << '\n';
    }
    return 0;
}