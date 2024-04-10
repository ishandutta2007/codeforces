#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 30;
const int MAXM = 1600005;
const int INF = 0x3f3f3f3f;
const char ltr[] = "LMW";

struct triple {
    int a, b, c;
    triple(int a, int b, int c) : a(a), b(b), c(c) {}
    triple() : a(0), b(0), c(0) {}
    bool operator <(const triple &rhs) const {
        if (a != rhs.a) return a < rhs.a;
        if (b != rhs.b) return b < rhs.b;
        return c < rhs.c;
    }
    void output() const {
        printf("%d %d %d\n", a, b, c);
    }
};

int N;
int a[MAXN][5];
map <triple, int> opt;
int mini[MAXM];
int best = -INF;
int x = -1, y = -1;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", a[i] + j);
}

void gen(int mask) {
    int mem = mask, tmp[5] = {0};
    for (int i = N / 2; i < N; i++) {
        for (int j = 0; j < 3; j++)
            tmp[j] += a[i][j];
        tmp[mask % 3] -= a[i][mask % 3];
        mask /= 3;
    }
    
    mini[mem] = *min_element(tmp, tmp + 3);
    for (int i = 0; i < 3; i++)
        tmp[i] -= mini[mem];
    
    triple t(tmp[0], tmp[1], tmp[2]);
    int &ref = opt[t];
    if (!ref || mini[mem] > mini[ref - 1])
        ref = mem + 1;
}

void merge(int mask) {
    int mem = mask, tmp[5] = {0};
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < 3; j++)
            tmp[j] += a[i][j];
        tmp[mask % 3] -= a[i][mask % 3];
        mask /= 3;
    }
    
    int maks = *max_element(tmp, tmp + 3);
    for (int i = 0; i < 3; i++)
        tmp[i] = maks - tmp[i];
    
    triple t(tmp[0], tmp[1], tmp[2]);
    int ref = opt[t];
    if (ref && maks + mini[ref - 1] > best) {
        best = maks + mini[ref - 1];
        x = mem;
        y = ref - 1;
    }
}

int pow(int x) {
    int res = 1;
    while (x--) res *= 3;
    return res;
}

void solve() {
    mini[0] = -INF;
    int pot1 = pow((N + 1) / 2);
    for (int i = 0; i < pot1; i++) 
        gen(i);
    
    int pot2 = pow(N / 2);
    for (int i = 0; i < pot2; i++)
        merge(i);
    
    if (x == -1 && y == -1) {
        puts("Impossible");
        return;
    }
    
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < 3; j++)
            if (j != x % 3) putchar(ltr[j]);
        puts("");
        x /= 3;
    }
    for (int i = N / 2; i < N; i++) {
        for (int j = 0; j < 3; j++)
            if (j != y % 3) putchar(ltr[j]);
        puts("");
        y /= 3;
    }
}

int main() {
    load();
    solve();
    return 0;
}