#include <bits/stdc++.h>

using namespace std;

vector < string > g;
vector < int > prom;
int n, k;
int ans = 1e9;
int use[10];

void dfs(int v){
    if (v == k){
        vector < int > Q;
        for (int i = 0; i < n; ++i){
            string p = "";
            for (auto key : prom) p += g[i][key - 1];
            //cout << p << endl;
            Q.push_back(stoi(p));
        }
        sort(Q.begin(), Q.end());
        ans = min(ans, Q.back() - Q.front());
    }
    else{
        for (int i = 1; i <= k; ++i){
            if (use[i] == 0){
                prom.push_back(i);
                use[i] = 1;
                dfs(v + 1);
                use[i] = 0;
                prom.pop_back();
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> s, g.push_back(s);
    dfs(0);
    cout << ans << endl;
    return 0;
}