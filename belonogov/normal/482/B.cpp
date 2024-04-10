#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <unordered_map>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define next nextt

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = 2e5 + 10;
const int ST = 30;
const int INF = 1e9;

struct query {
    int l, r, q;
    query() {}
};

struct event {
    int t, type, x;
    event() { }
    event(int t, int type, int x): t(t), type(type), x(x) { }
};

int n, m;
query a[N];
int answer[N];
int cnt[ST];
vector < event > b;
bool flag;
int next[N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].q); 
        a[i].l--;
    }
}

bool cmp(event a, event b) {
    return a.t < b.t;
}

void solve() {
    for (int i = 0; i < m; i++) {
        b.pb(event(a[i].l, 1, a[i].q));
        b.pb(event(a[i].r, -1, a[i].q));
    }
    sort(b.begin(), b.end(), cmp);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        for (; cur < (int)b.size() && b[cur].t <= i; cur++) {
            for (int j = 0; j < ST; j++)
                cnt[j] += b[cur].type * ((b[cur].x >> j) & 1);
        }
        for (int j = 0; j < ST; j++)
            if (cnt[j] > 0)
                answer[i] |= 1 << j;
    }
    flag = 1;
    for (int j = 0; j < ST; j++) {
        next[n] = n;
        for (int i = n - 1; i >= 0; i--) {
            next[i] = next[i + 1];
            if (((answer[i] >> j) & 1) == 0)
                next[i] = i;
        }
        for (int i = 0; i < m; i++) {
            if (((a[i].q >> j) & 1) == 0) {
                flag &= next[a[i].l] < a[i].r;
            }
        }
    }

}

void printAns() {
    if (flag) {
        printf("YES\n");
        for (int i = 0; i < n; i++)
            printf("%d ", answer[i]);
        printf("\n");
    }    
    else {
        printf("NO\n");
    }
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    freopen("test.txt", "r", stdin);
    freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}