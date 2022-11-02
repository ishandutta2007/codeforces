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
string s[2], t;
vector<int> p[2];
int nxt[2][55][26];
int get_pos(int id, int pos, int c) {
    if(pos == 0) {
        if(s[id][0]-'a' == c) return 1;
        return 0;
    }
    int &res = nxt[id][pos][c];
    if(res != -1) return res;
    if(s[id][pos] - 'a' == c) return res = pos + 1;
    res = get_pos(id, p[id][pos-1], c);
    return res;
}
int dp[1010][52][52];
bool u[1010][52][52];
int get(int pos, int x, int y) {
    //cout << pos << " " << x <<  " " << y << '\n';
    if(pos == t.size()) return 0;
    int &res = dp[pos][x][y];
    if(u[pos][x][y]) return res;
    u[pos][x][y] = 1;
    res = -inf;
    for(int i = 0; i < 26; i++) {
        if(t[pos] == '*' || t[pos]-'a' == i) {
            int px = get_pos(0, x, i);
            int py = get_pos(1, y, i);
            int cnt = 0;
            if(px == s[0].size()) {
                cnt++;
                px = p[0][px-1];
            }
            if(py == s[1].size()) {
                cnt--;
                py = p[1][py-1];
            }
            res = max(res, get(pos + 1, px, py) + cnt);
        }
    }
    return res;
}
void solve() {
    cin >> t >> s[0] >> s[1];
    p[0] = prefix_function(s[0]);
    p[1] = prefix_function(s[1]);
    memset(nxt, -1, sizeof nxt);
    cout << get(0, 0, 0) << "\n";
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