#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int k;

struct Trie {
    char pch;
    int go[14];
    int next[14];
    int link = -1;
    int par;
    int finish = 0;
    int val = -2e9;
    Trie(int par = -1, char pch = '$') : par(par), pch(pch) {
        memset(next, -1, 14 * 4);
        memset(go, -1, 14 * 4);
    }
};

vector<Trie> trie(1);
    
void insert(string s, int val) {
    int cur = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[cur].next[c] == -1) {
            trie[cur].next[c] = trie.size();
            trie.push_back(Trie(cur, ch));
        }
        cur = trie[cur].next[c];
    }
    trie[cur].finish += val;
}

int go(int u, char ch);

int getlink(int v) {
    if (trie[v].link != -1) return trie[v].link;
    if (v == 0 || trie[v].par == 0) trie[v].link = 0;
    else trie[v].link = go(getlink(trie[v].par), trie[v].pch);
    return trie[v].link; 
}

int go(int u, char ch) {
    int c = ch - 'a';
    if (trie[u].go[c] == -1) {
        if (trie[u].next[c] != -1) trie[u].go[c] = trie[u].next[c];
        else if (u != 0) trie[u].go[c] = go(getlink(u), 'a' + c);
        else trie[u].go[c] = 0;     
    }
    return trie[u].go[c];
}

int calc(int u) {
    if (trie[u].val != -2e9) return trie[u].val;
    if (u == 0) {
        trie[u].val = 0;
    } else {
        trie[u].val = trie[u].finish + calc(getlink(u));
    }
    return trie[u].val;
}

long long dp[1005][1 << 14];
long long tmp[1005][1 << 14];
pair<int, long long> fr[1005];
vector<int> nbit[14];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> k;
    for (int i = 1; i <= k; i++) {
        string s;
        int val;
        cin >> s >> val;
        insert(s, val);
    }
    for (int i = 0; i < (1 << 14); i++) {
        nbit[__builtin_popcount(i)].pb(i);
    }
    string t;
    cin >> t; t = " " + t;
    vector<int> ques;
    for (int i = 0; i < t.size(); i++) if (t[i] == '?') ques.pb(i);
    ques.pb(t.size());
    int cur = 0;
    for (int i = 0; i < trie.size(); i++) {
        for (int j = 0; j < (1 << 14); j++) {
            dp[i][j] = -1e18;
            tmp[i][j] = -1e18;
        }
    }
    dp[0][0] = 0;
    long long ans = -1e18;
    int cnt = 0;
    for (int e : ques) {
        cnt++;
        for (int i = 0; i < trie.size(); i++) {
            fr[i] = {i, 0}; 
        }
        while (cur + 1 < e) {
            cur++;
            for (int i = 0; i < trie.size(); i++) {
                fr[i].x = go(fr[i].x, t[cur]);
                fr[i].y += calc(fr[i].x);
            }
        }
        for (int i = 0; i < trie.size(); i++) {
            for (int j : nbit[cnt - 1]) {
                tmp[fr[i].x][j] = max(tmp[fr[i].x][j], dp[i][j] + fr[i].y); 
                dp[i][j] = -1e18;
            }
        }
        if (e == t.size()) {
            for (int i = 0; i < trie.size(); i++) {
                for (int j : nbit[cnt - 1]) {
                    ans = max(ans, tmp[i][j]);
                }
            }
            break;
        }
        for (int i = 0; i < trie.size(); i++) {
            for (int j : nbit[cnt - 1]) {
                if (tmp[i][j] < -5e17) continue;
                for (int k = 0; k < 14; k++) {
                    int foo = go(i, 'a' + k);
                    if (bit(j, k) == 1) continue;
                    dp[foo][j ^ (1 << k)] = max(tmp[i][j] + calc(foo), dp[foo][j ^ (1 << k)]);
                }
                tmp[i][j] = -1e18;
            }
        }
        cur++;
    }
    cout << ans;
    return 0;
}