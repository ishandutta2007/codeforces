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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 222;
const long long INF = 1e9 + 19;
const int ALF = 26;

struct Node {
    int next[ALF];
    int go[ALF];
    int p, pch;
    int cost;
    int link;
    Node() {
        memset(next, -1, sizeof(next)); 
        memset(go, -1, sizeof(go));
        cost = 0;
        link = -1;
    }
};

int n;
long long l;
int c[N];
char s[N];
int cur = 1;
Node data[N];
int dp[N * N* 2][N];
int dp2[N][N][N];


void add(char * s, int len, int cost) {
    int v = 0;  
    for (int i = 0; i < len; i++) {
        int ch = s[i] - 'a';
        if (data[v].next[ch] == -1) {
            data[v].next[ch] = cur;
            data[cur].p = v;
            data[cur].pch = ch;
            cur++;
        }
        v = data[v].next[ch];
    }
    data[v].cost += cost;
}



void build() {
    queue < int > q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == 0 || data[v].p  == 0) {
            data[v].link = 0;
        }   
        else {
            data[v].link = data[data[data[v].p].link].go[data[v].pch];
        }

        for (int i = 0; i < ALF; i++) {
            if (data[v].next[i] != -1) {
                data[v].go[i] = data[v].next[i];
                q.push(data[v].next[i]);
            }
            else {
                if (v == 0)
                    data[v].go[i] = 0;
                else 
                    data[v].go[i] = data[data[v].link].go[i];
            }
        }
        data[v].cost += data[data[v].link].cost;
    }
}




void read() {
    scanf("%d%lld", &n, &l);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int len = strlen(s);
        add(s, len, c[i]);
    }
}

void upd(int & a, int b) {
    a = max(a, b);
}

void solve() {
    build();
    memset(dp, -63, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 0; i < cur * (cur + 1); i++) 
        for (int j = 0; j < cur; j++) {
            for (int k = 0; k < ALF; k++) {
                upd(dp[i + 1][data[j].go[k]], dp[i][j] + data[data[j].go[k]].cost);
            }
        }
    memset(dp2, -63, sizeof(dp2));   
    for (int st = 0; st < cur; st++) {
        dp2[st][0][st] = 0;      
        for (int i = 0; i < cur; i++)
            for (int j = 0; j < cur; j++)
                for (int k = 0; k < ALF; k++)
                    upd(dp2[st][i + 1][data[j].go[k]], dp2[st][i][j] + data[data[j].go[k]].cost);
    }

    //db(dp2[0][2][0]);

    //for (int i = 0; i <= l; i++, cerr << endl)
        //for (int j = 0; j < 10; j++)
            //cerr << dp[i][j] << " ";


    vector < int > best(cur + 1);
    for (int step = 1; step <= cur; step++) {
        int mx = 0;
        for (int i = 0; i < cur; i++)
            mx = max(mx, dp2[i][step][i]);
        best[step] = mx;
    }
    

    long long answer = 0;
    for (int step = 1; step <= cur; step++) {
        //db(step);
        for (int i = 0; i < cur; i++) {
            if (l < cur * (cur + 1)) {
                answer = max(answer, dp[l][i] * 1ll);
            }
            else {
                int rem = (l - cur * cur) % step;
                int p2 = cur * cur + rem;
                //int p1 = p2 - step;
                //db2(p1, p2);
                //int diff = dp[p2][i] - dp[p1][i];
                //int diff = dp2[i][step][i];
                //if (diff < 0) continue;
                assert((l - p2) % step == 0);
                long long cnt = (l - p2) / step;
                //db2(cnt, diff);
                answer = max(answer, dp[p2][i] + cnt * best[step]);
            }
        }

    }
    printf("%lld\n", answer);
}

void stress() {

}


int main(){
#ifdef MY_DEBUG
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