#include <bits/stdc++.h>

using namespace std;
const int maxn = (int)1e6 + 100;
int n, m;
int a[maxn];
int d[maxn];
int pr[maxn];
vector<int> g[maxn];
int T;
int used[maxn];
int dis[maxn];
int p[maxn];
map< pair<char, char>, int> id;
pair<char, char> val[maxn];
int sz = 0;
int getId(char a, char b) {
    if(id.count(make_pair(a, b)) == 0) {
        id[{a, b}] = sz;
        val[sz] = {a, b};
        sz++;
    }
    return id[{a, b}];
}
int inD[maxn];
int outD[maxn];
vector<int> ans;
void dfs(int v) {
    while(g[v].size() > 0) {
        int to = g[v].back();
        g[v].pop_back();
        dfs(to);
    }
    ans.push_back(v);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        g[getId(s[0], s[1])].push_back(getId(s[1], s[2]));
    }
    for(int i = 0; i < sz; i++) {
        for(int to: g[i]) {
            outD[i]++;
            inD[to]++;
        }
    }
    int st = 0;
    int cnt = 0;
    for(int i = 0; i < sz; i++) {
        if(abs(inD[i] - outD[i]) > 1) {
            cout << "NO\n";
            return 0;
        }
        if(inD[i] < outD[i]) {
            ++cnt;
            st = i;
        }
    }
    if(cnt > 1) {
        cout << "NO\n";
        return 0;
    }
    dfs(st);
    reverse(ans.begin(), ans.end());
    if(ans.size() != n + 1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << val[ans[0]].first << val[ans[0]].second;
    for(int i = 1; i < ans.size(); i++) {
        cout << val[ans[i]].second;
    }
}