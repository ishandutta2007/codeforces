#include <bits/stdc++.h>
using namespace std;

const int N = 200001;
vector<int> g[N];
int pre1[N], pre2[N];
bool vis[N];

int main(void){
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
    }

    bool found = false;
    mt19937_64 mt(time(0));
    int T = 40;
    while (T--) {
        fill_n(pre1 + 1, n, 0);
        fill_n(pre2 + 1, n, 0);
        queue<int> q1, q2;
        pre1[s] = pre2[s] = -1;
        for (int v : g[s]) {
            if (mt() & 1)
                pre1[v] = s, q1.push(v);
            else 
                pre2[v] = s, q2.push(v);
        }

        while (!q1.empty()) {
            int u = q1.front();
            q1.pop();
            for (int v : g[u]) {
                if (pre1[v]) continue;
                pre1[v] = u;
                q1.push(v);
            }
        }

        while (!q2.empty()) {
            int u = q2.front();
            q2.pop();
            for (int v : g[u]) {
                if (pre2[v]) continue;
                pre2[v] = u;
                q2.push(v);
            }
        }

        for (int u = 1; u <= n; ++u) {
            if (u == s) continue;
            if (pre1[u] == 0 || pre2[u] == 0) continue;
            found = true;
            printf("Possible\n");
            int v1 = u, v2 = u;
            vector<int> p1, p2;
            while (v1 != s) {
                // if (pre1[v1] != 0 && pre2[v1] != 0)
                //     p1.clear();
                p1.push_back(v1);
                v1 = pre1[v1];
            }
            while (v2 != s) {
                // if (pre1[v2] != 0 && pre2[v2] != 0)
                //     p2.clear();
                p2.push_back(v2);
                v2 = pre2[v2];
            }
            p1.push_back(s);
            p2.push_back(s);
            reverse(p1.begin(), p1.end());
            reverse(p2.begin(), p2.end());
            fill_n(vis + 1, n, 0);
            for (int i : p2)
                if (i != s)
                    vis[i] = 1;
            
            int t = 0;
            for (int i : p1) {
                if (vis[i]) {
                    t = i;
                    break;
                }
            }

            while (p1.back() != t)
                p1.pop_back();
            while (p2.back() != t)
                p2.pop_back();

            printf("%d\n", (int)p1.size());
            for (int i = 0; i < p1.size(); ++i)
                printf("%d%c", p1[i], " \n"[i + 1 == (int)p1.size()]);
            printf("%d\n", (int)p2.size());
            for (int i = 0; i < p2.size(); ++i)
                printf("%d%c", p2[i], " \n"[i + 1 == (int)p2.size()]);
            break;
        }
        if (found) break;
    }
    if (!found)
        printf("Impossible\n");
    return 0;
}