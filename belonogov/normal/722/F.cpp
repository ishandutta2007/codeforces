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
#define sz(a) (int)a.size()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
const int K = 41;

int n, m;
int when[N][K];
int rem[N][K];
int l[N];
int r[N];
int answer[N];
int len[N];

bool isValid(int r1, int m1, int r2, int m2) {
    int d = __gcd(m1, m2);
    return r1 % d == r2 % d;
}

void read() {
    scanf("%d%d", &n, &m);  
    for (int i = 0; i < m; i++)
        r[i] = -2;
    memset(when, -1, sizeof(when));

    for (int i = 0; i < n; i++) {
        scanf("%d", &len[i]);
        for (int j = 0; j < len[i]; j++) {
            //db2(i, j);
            int x;
            scanf("%d", &x); x--;

            if (r[x] + 1 != i)
                l[x] = i;
            r[x] = i;

            //if (i == 2 && x == 2)
                //db("!!!");
            for (int t = 1; t < K; t++)
                if (l[x] <= when[x][t] && !isValid(rem[x][t], len[when[x][t]], j, len[i])) {
                    //if (i == 2 && x == 2) {
                        //db(when[x][t]);
                    //}

                    l[x] = when[x][t] + 1;
                }

            when[x][len[i]] = i;
            rem[x][len[i]] = j;
            

            //if (i == 2 && x == 2) db(l[x]);
            answer[x] = max(answer[x], i - l[x] + 1);
        }

    }
    for (int i = 0; i < m; i++)
        printf("%d\n", answer[i]);

}

void solve() {

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