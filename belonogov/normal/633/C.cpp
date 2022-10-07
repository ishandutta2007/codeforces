#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;
const int ALF = 26;

struct Node {
    int next[ALF];
    int id;
    Node() {
        memset(next, -1, sizeof(next));
        id = -1;
    }
};

int n, m;
string s;
string t[N];
int cur = 1;
Node data[N];


void add(string g, int id) {
    reverse(g.begin(), g.end());
    for (auto &ch: g) 
        if (isupper(ch))
            ch = ch - 'A' + 'a';
    int v = 0;
    for (int i = 0; i < (int)g.size(); i++) {
        int ch = g[i] - 'a';
        //db(ch);
        if (data[v].next[ch] == -1) {
            data[v].next[ch] = cur;
            cur++;
        }
        v = data[v].next[ch];
    }
    data[v].id = id;
}


void read() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    cin >> s;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }
}

int dp[N];
int p[N];

void solve() {
    for (int i = 0; i < m; i++) {
        add(t[i], i);
    }

    dp[0] = 1;
    memset(p, -1, sizeof(p));
    for (int i = 0; i < n; i++) {
        if (dp[i]) {
            int v = 0;
            for (int j = i + 1; j <= n; j++) {
                int ch = s[j - 1] - 'a';
                if (data[v].next[ch] == -1) break;
                v = data[v].next[ch];
                if (data[v].id != -1) {
                    if (dp[j] == 0) {
                        dp[j] = 1;
                        p[j] = data[v].id;
                    }
                }
            }

        } 

    }
    //for (int i = 0; i <= n; i++)
        //cerr << dp[i] << " ";
    //cerr << endl;


    assert(dp[n]);

    vector < int > answer; 
    int v = n;
    for (; v != 0; ) {
        answer.pb(p[v]);
        v = v - t[p[v]].size();
    }
    reverse(answer.begin(), answer.end());
    for (auto x: answer)
        cout << t[x] << " ";
    cout << endl;
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}