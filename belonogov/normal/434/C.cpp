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
#define left lefttt
#define right righttt
const int N = 555;
const long long INF = 1e9 + 19;
const int T = 222;
const int MOD = 1e9 + 7;

int m;

struct Node {
    vector < int > next;
    vector < int > go;
    int link;
    int cost;
    int par, pch;
    void init(int m, int p, int ch) {
        next.assign(m, -1);
        go.assign(m, -1);
        link = -1;
        par = p;
        pch = ch;
    }
};

int n, k;
vector < int > left;
vector < int > right;
int nextFree = 1;
Node node[N];
int dp[T][T][N][2];


void add(vector < int > & data, int k) {
    int v = 0;
    for (int i = 0; i < (int)data.size(); i++) {
        int ch = data[i];
        if (node[v].next[ch] == -1) {
            node[v].next[ch] = nextFree;
            node[nextFree].init(m, v, ch);
            nextFree++;
        }
        v = node[v].next[ch];
    }
    node[v].cost += k;
}

void upd(int & a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

long long calc(vector < int > right) {
    memset(dp, 0, sizeof(dp)); 
    int len = right.size();
    //dp[len][0][0][1] = 1;
    for (int j = 1; j <= right.back(); j++) {
        int nv = node[0].go[j];
        int nk = node[nv].cost;
        if (nk <= k)
            upd(dp[len - 1][nv][nk][j == right.back()], 1);
    }
    for (int i = len - 2; i >= 0; i--) {
        for (int j = 1; j < m; j++) {
            int nv = node[0].go[j];
            int nk = node[nv].cost;
            //db2(nv, nk);
            //db(i);
            if (nk <= k)
                upd(dp[i][nv][nk][0], 1);
        }
    }

    for (int i = len; i > 0; i--) {
        for (int v = 0; v < nextFree; v++)
            for (int curK = 0; curK <= k; curK++) {
                for (int type = 0; type < 2; type++) {
                    if (dp[i][v][curK][type] == 0) continue;
                    for (int next = 0; next < m; next++) {
                        if (type && next > right[i - 1]) continue;
                        int nv = node[v].go[next];
                        int nk = node[nv].cost + curK;
                        if (nk <= k)
                            upd(dp[i - 1][nv][nk][type && next == right[i - 1]], dp[i][v][curK][type]);
                    }

                }
            }    
    }
    int sum = 0;
    for (int v = 0; v < nextFree; v++)
        for (int curK = 0; curK <= k; curK++)
            upd(sum, dp[0][v][curK][0]);

    return sum;
}

void read() {
    scanf("%d%d%d", &n, &m, &k);
    int tmp;
    scanf("%d", &tmp);
    left.resize(tmp);
    for (int i = 0; i < tmp; i++)
        scanf("%d", &left[i]);
    scanf("%d", &tmp);
    right.resize(tmp);
    for (int i = 0; i < tmp; i++)
        scanf("%d", &right[i]);


    node[0].init(m, -1, -1);
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        vector < int > data(tmp);
        for (int j = 0; j < tmp; j++)
            scanf("%d", &data[j]);
        int k;
        scanf("%d", &k);
        add(data, k);
    }
}

void build() {
    queue < int > q; 
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < m; i++)
            if (node[v].next[i] != -1)
                q.push(node[v].next[i]);
        if (node[v].par == -1 || node[v].par == 0)
            node[v].link = 0;
        else {
            int par = node[v].par;
            node[v].link = node[node[par].link].go[node[v].pch];
        }
        for (int i = 0; i < m; i++)
            if (node[v].next[i] != -1)
                node[v].go[i] = node[v].next[i];
        if (v == 0) {
            for (int i = 0; i < m; i++)
                if (node[v].go[i] == -1)
                    node[v].go[i] = 0;
        }
        else {
            for (int i = 0; i < m; i++)
                if (node[v].go[i] == -1)
                    node[v].go[i] = node[node[v].link].go[i];
        }
        node[v].cost += node[node[v].link].cost;
    }
}


void solve() {
    reverse(left.begin(), left.end());
    reverse(right.begin(), right.end());
    right[0]++;
    int cur = 0;
    for (; cur < (int)right.size() && right[cur] >= m; cur++) {
        right[cur] -= m;
        if (cur + 1 == (int)right.size())
            right.pb(1);
        else
            right[cur + 1]++;
    }
    build();
 
    int r1 = calc(right);
    int r2 = calc(left); 
    cout << (r1 - r2 + MOD) % MOD << endl; 
}

void printAns() {

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
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}