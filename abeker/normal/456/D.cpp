#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 100005;

struct node {
    int idx[30];
    node() {
        memset(idx, -1, sizeof idx);
    }    
};

int N, K;
char s[MAXN];
node t[MAXN];
int sz;

int dp[MAXN][2];

void add(string x) {
    int c = 0; 
    for (int i = 0; i < x.size(); i++) {
        if (t[c].idx[x[i] - 'a'] == -1) 
            t[c].idx[x[i] - 'a'] = ++sz;
        c = t[c].idx[x[i] - 'a'];
    }
}

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%s", s);
        add(s);
    }
}

void dfs(int x) {
    int leaf = 1;
    for (int i = 0; i < 26; i++) {
        int c = t[x].idx[i];
        if (c == -1) continue;
        leaf = 0;
        dfs(c);
        if (!dp[c][0]) dp[x][0] = 1;
        if (!dp[c][1]) dp[x][1] = 1;
    }
    if (leaf) {
        dp[x][0] = 0;
        dp[x][1] = 1;
    }
}

int solve() {
    dfs(0);
    if (!dp[0][0]) return 0;
    if (dp[0][0] && dp[0][1]) return 1;
    return K % 2;
}

void debug() {
    for (int i = 0; i < 10; i++, puts("")) 
        for (int j = 0; j < 30; j++) 
            printf("%d ", t[i].idx[j]);
}

int main() {
    load();
    puts(solve() ? "First" : "Second");
    return 0;
}