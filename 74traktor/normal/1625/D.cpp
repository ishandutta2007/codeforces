#include<bits/stdc++.h>

using namespace std;

int const maxn = 3e5 + 5;
int a[maxn];
int nxt[maxn * 30][2];
int cur = 1;
int stop[maxn * 30];

inline void add(int b, int x, int ind) {
    int node = 0;
    while (b >= 0) {
        int t = min(1, (x >> b)&1);
        if (nxt[node][t] == 0) nxt[node][t] = cur++;
        node = nxt[node][t];
        b--;
    }
    stop[node] = ind;
}

vector < int > solve(int b, int k, vector < int > pos) {
    if (b == -1 || (int)pos.size() == 0) return pos;
    vector < int > L, R;
    for (auto key : pos) {
        if ((a[key]&(1 << b))) L.push_back(key);
        else R.push_back(key);
    }
    int t = min(1, (k>>b));
    if (t == 0) {
        vector < int > ans = solve(b - 1, k, L);
        for (auto key : solve(b - 1, k, R)) ans.push_back(key);
        return ans;
    } else {
        for (auto key : pos) {
            add(b, a[key], key);
        }
        vector < int > ans;
        int B = b;
        for (auto key : pos) {
            int node = 0, flag = 0;
            b = B;
            while (b >= 0) {
                int t = min(1, (k>>b)&1);
                int now = min(1, (a[key]>>b)&1);
                int need = 1;
                for (int oth = 0; oth <= 1 && !flag; ++oth) {
                    if ((oth^now) > t && nxt[node][oth] != 0 && need) {
                        node = nxt[node][oth];
                        flag = 1;
                        need = 0;
                    }
                }
                if (need) {
                    for (int oth = 0; oth <= 1; ++oth) {
                        if ((flag || (oth^now) >= t) && nxt[node][oth] != 0 && need) {
                            node = nxt[node][oth];
                            need = 0;
                        }
                    }
                }
                if (need) break;
                b--;
            }
            if (b == -1) {
                ans = {key, stop[node]};
            }
        }
        for (int i = 0; i <= cur; ++i) nxt[i][0] = 0, nxt[i][1] = 0;
        cur = 1;
        if ((int)ans.size() == 0) ans = {pos[0]};
        return ans;
    }
}

main() {
#ifdef karpovich
    freopen("input.txt", "r", stdin);
#endif // karpovich
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, x;
    cin >> n >> k;
    vector < int > pos;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos.push_back(i);
    }
    vector < int > ans = solve(29, k, pos);
    if ((int)ans.size() < 2) {
        cout << -1;
        exit(0);
    }
    cout << ans.size() << '\n';
    for (auto key : ans) cout << key << " ";
    return 0;
}