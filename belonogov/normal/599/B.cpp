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
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;

int n, m;
int f[N];
int b[N];
int a[N];
int rev[N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &f[i]);
        f[i]--;
    }
    for (int i = 0; i < m; i++)  {
        scanf("%d", &b[i]);
        b[i]--;
    }
}

void solve() {
    memset(rev, -1, sizeof(rev)); // -1 mean undefined
                        // -2 mean at least two equal variables
    for (int i = 0; i < n; i++) {
        if (rev[f[i]] == -1)
            rev[f[i]] = i;
        else
            rev[f[i]] = -2;
    }

    bool flagAmb = 0;
    bool flagImp = 0;
    for (int i = 0; i < m; i++) {
        if (rev[b[i]] >= 0)
            a[i] = rev[b[i]];
        flagAmb |= rev[b[i]] == -2;
        flagImp |= rev[b[i]] == -1;
    }
    if (flagImp) {
        puts("Impossible");
        return;
    }
    if (flagAmb) {
        puts("Ambiguity");
    }
    else {
        puts("Possible");
        for (int i = 0; i < m; i++)
            printf("%d ", a[i] + 1);
        puts("");
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