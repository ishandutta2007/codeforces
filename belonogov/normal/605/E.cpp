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
#define get gettt
const int N = 1111;
const long long INF = 1e9 + 19;

int p[N][N];
double dist[N];
bool get[N];
bool calc[N];
double sub[N];
double sum[N];
int n;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            p[i][j] = x;
            //p[i][j] = x / 100.0;
        }
}

void solve() {
    dist[n - 1] = 0;
    calc[n - 1] = 1;
    for (int i = 0; i < n; i++)
        sub[i] = 1;
    for (int i = 0; i < n; i++)
        sum[i] = 1;

    for (int tt = 0; ; tt++) {
        int best = -1;
        for (int i = 0; i < n; i++) {
            if (get[i]) continue;
            if (!calc[i]) continue;
            if (best == -1 || dist[i] < dist[best])
                best = i;
        }
        if (best == 0) {
            printf("%.17f\n", dist[0]);
            return;
        }
        get[best] = 1;
        for (int i = 0; i < n; i++) {
            if (get[i]) continue;
            if (p[i][best] == 0) continue;
            double prob = p[i][best] / 100.0;
            sum[i] += sub[i] * prob * dist[best];
            sub[i] = sub[i] * (1 - prob);  
            double nr = sum[i] / (1 - sub[i]);
            if (!calc[i]) {
                calc[i] = 1;
                dist[i] = nr;
            }
            else {
                //assert(nr <= dist[i]);
                dist[i] = nr;
            }
        }
    }


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