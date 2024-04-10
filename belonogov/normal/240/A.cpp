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
const int N = 1111;
const long long INF = 1e9 + 19;

int m, k;
bool love[N];
int n;
int l[N];
int r[N];
char s[N];

void read() {
    scanf("%d%d", &m, &k);
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x); x--;
        love[x] = 1;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int t;
        scanf("%d", &t);
        int cnt = 0;
        int empty = 0;
        for (int j = 0; j < t; j++) {
            int x;
            scanf("%d", &x); x--;
            if (x != -1)
                cnt += love[x];
            else
                empty++;
        }
        r[i] = min(k, cnt + empty);
        int tmp = (m - k) - (t - cnt - empty);
        l[i] = cnt + max(0, empty - tmp);
    }
    //for (int i = 0; i < n; i++)
        //db2(l[i], r[i]);

    for (int i = 0; i < n; i++) {
        int mxR = 0; 
        int mxL = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            mxR = max(mxR, r[j]);
            mxL = max(mxL, l[j]);
        }
        int ans = -1;
        if (l[i] >= mxR)
            ans = 0;
        else if (r[i] < mxL)
            ans = 1;
        else
            ans = 2;
        printf("%d\n", ans);
    }
}

void solve() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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