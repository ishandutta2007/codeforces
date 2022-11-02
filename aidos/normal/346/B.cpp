#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> p(n, 0);
    for(int i = 1; i < n; i++) {
        int z = p[i-1];
        while(z > 0 && s[z] != s[i]) z = p[z-1];
        if(s[z] == s[i]) z++;
        p[i] = z;
    }
    return p;
}
string s, t, virus;
vector<int> p;
int nxt[155][26];
int get_pos(int pos, int c) {
    if(pos == 0) {
        if(virus[0]-'A' == c) return 1;
        return 0;
    }
    int &res = nxt[pos][c];
    if(res != -1) return res;
    if(virus[pos] - 'A' == c) return res = pos + 1;
    res = get_pos(p[pos-1], c);
    return res;
}
int dp[101][101][101];
int get(int pos, int x, int y) {
    //cout << pos << " " << x <<  " " << y << '\n';
    if(pos == t.size()) return 0;
    if(x == s.size()) return 0;
    int &res = dp[pos][x][y];
    if(res != -1) return res;
    res = max(get(pos+1, x, y), get(pos, x+1, y));
    if(t[pos] == s[x]) {
        int px = get_pos(y, s[x] - 'A');
        if(px != virus.size()) res = max(res, get(pos+1, x+1, px) + 1);
    }
    return res;
}
string rec(int pos, int x, int y) {
    //cout << pos << " " << x <<  " " << y << '\n';
    if(pos == t.size()) return "";
    if(x == s.size()) return "";
    if(get(pos, x, y) == get(pos+1, x, y)) {
        return rec(pos+1, x, y);
    }
    if(get(pos, x, y) == get(pos, x+1, y)) {
        return rec(pos, x + 1, y);
    }
    if(t[pos] == s[x]) {
        int px = get_pos(y, s[x] - 'A');
        if(px != virus.size()) return s[x] + rec(pos+1, x+1, px);
    }
    return "";
}
void solve() {
    cin >> t >> s >> virus;
    p = prefix_function(virus);
    memset(nxt, -1, sizeof nxt);
    memset(dp, -1, sizeof dp);
    if(get(0, 0, 0) > 0)
        cout << rec(0, 0, 0) << "\n";
    else cout << 0 << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}