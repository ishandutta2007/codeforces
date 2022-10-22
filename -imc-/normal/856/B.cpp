#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

int xrand() { return abs((rand() << 16) + rand()); }

int add(int a, int b) {
    a += b;
    while (a > 1e6) a -= 1e6;
    return a;
}

int MOD[2] = { (int)1e9 + 7, (int)1e9 + 25 };
int BASE[2] = { 23, 101 };

vector<vector<int>> e;
vector<array<int, 2>> dp;

vector<char> not_root;

void dfs(int v) {
    for (int u: e[v]) {
        dfs(u);
    }
    
    int zero_sum = 0, one_sum = 0;
    for (int u: e[v]) {
        zero_sum += dp[u][0];
        one_sum += max(dp[u][0], dp[u][1]);
    }
    
    dp[v][1] = 1 + zero_sum;
    dp[v][0] = one_sum;
}

void solve(bool read) {
    int n;
    if (read)
        cin >> n;
    else {
        n = rand() % 3 + 1;
        printf("%d\n", n);
    }
    
    map<array<int, 2>, int> prefix_id;
    
    int n_verts = 1;
    
    vector<string> s(n);
    vector<int> ids;
    for (int iter = 0; iter < 2; iter++) {
        int cur_id = 0;
        
        for (int i = 0; i < n; i++) {
            if (iter == 0) {
                if (read)
                    cin >> s[i];
                else {
                    int x = rand() % 5 + 1;
                    for (int j = 0; j < x; j++)
                        s[i] += 'a' + rand() % 2;
                    printf("%s\n", s[i].c_str());
                }
            }
            else
                s[i] = s[i].substr(1);
            
            int l = s[i].length();
            
            array<int, 2> power = {{ 1, 1 }}, h = {{ 0, 0 }};
            
            for (int j = 0; j < l; j++) {
                for (int t = 0; t < 2; t++) {
                    h[t] += power[t] * (s[i][j] - 'a' + 1);
                    power[t] = power[t] * (li)BASE[t] % MOD[t];
                }
                
                if (iter == 0) {
                    if (!prefix_id.count(h))
                        prefix_id[h] = n_verts++;
                    
                    ids.push_back(prefix_id[h]);
                }
                else if (prefix_id.count(h)) {
                    e[prefix_id[h]].push_back(ids[cur_id + j + 1]);
                    not_root[ids[cur_id + j + 1]] = true;
                }
            }
            if (iter == 1) {
                e[0].push_back(ids[cur_id]);
                not_root[ids[cur_id]] = true;
            }
            cur_id += l + (iter == 1);
        }
        //printf("ids: "); for (int x: ids) printf("%d ", x); printf("\n");
        //printf("cur id %d\n", cur_id);
        
        if (iter == 0) {
            e.clear();
            dp.clear();
            not_root.clear();
            e.resize(n_verts);
            dp.resize(n_verts);
            not_root.resize(n_verts);
        }
    }
    
    for (int i = 0; i < e.size(); i++) {
        sort(all(e[i]));
        e[i].erase(unique(all(e[i])), e[i].end());
    }
    
#if 0
    for (int i = 0; i < e.size(); i++) {
        printf("%d (%d) edges: ", i, not_root[i]);
        for (int x: e[i])
            printf("%d ", x);
        printf("\n");
    }
#endif
    
    int answer = 0;
    for (int i = 0; i < e.size(); i++)
        if (!not_root[i]) {
            dfs(i);
            answer += (i == 0 ? dp[i][0] : max(dp[i][1], dp[i][0]));
        }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt;
    cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //for (int i = 0; i < 500; i++)
    //    solve(false);
    
    return 0;
}