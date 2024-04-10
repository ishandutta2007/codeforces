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
const int N = 1000 + 10;
const long long INF = 1e9 + 19;

struct Event {
    int in, out, w, s, v;
    void read() {
        scanf("%d%d %d%d%d", &in, &out, &w, &s, &v);
    }
};

int n, S;
int dp[N][N];
Event a[N];
int help[N];

void read() {
    scanf("%d%d", &n, &S);
    for (int i = 0; i < n; i++) {
        a[i].read();
    }

}

bool cmpIn(Event a, Event b) {
    return a.in < b.in || (a.in == b.in && a.out > b.out);
}

void solve() {
    a[n].in = 0;
    a[n].out = n * 2 + 1;
    a[n].w = 0;
    a[n].s = S + 10;
    a[n].v = 0;
    n++;
    memset(dp, -63, sizeof(dp));
    sort(a, a + n, cmpIn);
    //for (int i = 0; i < n; i++)
        //dp[i][a[i].w] = a[i].v;
    for (int i = n - 1; i >= 0; i--) {
        for (int s = 0; s <= S; s++) {
            if (s - a[i].w < 0) continue;
            if (s - a[i].w > a[i].s) continue;
            memset(help, 0, sizeof(help));
            int cur = n * 2;
            for (int j = n - 1; j > i; j--) {
                for (; cur > a[j].in; cur--)
                    help[cur - 1] = max(help[cur], help[cur - 1]);
                if (a[j].out > a[i].out) continue;
                help[a[j].in] = max(help[a[j].in], dp[j][s - a[i].w] + help[a[j].out]);

            }
            for (; cur > a[i].in; cur--)
                help[cur - 1] = max(help[cur], help[cur - 1]);
            dp[i][s] = help[a[i].in] + a[i].v;
        }
        for (int s = 1; s <= S; s++)
            dp[i][s] = max(dp[i][s - 1], dp[i][s]);
    }
    //for (int i = 0; i < n; i++, cerr << endl)
        //for (int j = 0; j <= S; j++)
            //cerr << dp[i][j] << " ";

    int mx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= S; j++)
            mx = max(dp[i][j], mx);


    cout << mx << endl;
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