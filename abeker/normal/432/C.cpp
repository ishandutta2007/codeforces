#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100005;

struct par {
    int x, y;
    par(int _x, int _y) { x = _x; y = _y; }
    void output() const { printf("%d %d\n", x, y); }
    par(){}
};

bool ok[MAXN];
int t[MAXN];

void sieve() {
    for (int i = 2; i < MAXN; i++)
        if (!ok[i]) {
            t[i - 1] = i - 1;
            for (int j = i; j < MAXN; j += i) 
                ok[j] = true;
        }
    for (int i = 1; i < MAXN; i++) 
        if (!t[i]) t[i] = t[i - 1];
}

int N;
int a[MAXN], pos[MAXN];
vector <par> v;

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) 
        scanf("%d", a + i);
}

void work(int x) {
    if (x == pos[x]) return;
    int l, r;
    if (x > pos[x]) {
        l = pos[x];
        r = pos[x] + t[x - pos[x]];
    }
    else {
        l = pos[x] - t[pos[x] - x]; 
        r = pos[x];
    }
    swap(pos[a[l]], pos[a[r]]);
    swap(a[l], a[r]);
    v.push_back(par(l, r));
    work(x);
}

void solve() {
    for (int i = 1; i <= N; i++) 
        pos[a[i]] = i;
    for (int i = 1; i <= N; i++)
        work(i);
    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); i++) 
        v[i].output(); 
}

int main() {
    sieve();
    load();
    solve();
    return 0;
}