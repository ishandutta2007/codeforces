#include <cstdio>
using namespace std;

const int MAXN = 1005;

int N, P;
char s[MAXN], c[MAXN];

void load() {
    scanf("%d%d%s", &N, &P, s);
}

bool ok(int letter, int pos, int first) {
    if (pos > 0 && letter == c[pos - 1] - 'a') return 0;
    if (pos > 1 && letter == c[pos - 2] - 'a') return 0;
    if (pos == first && letter <= s[pos] - 'a') return 0;
    return 1;
}

bool construct(int x) {
    for (int i = 0; i < x; i++) 
        c[i] = s[i];
    for (int i = x; i < N; i++) {
        bool flag = 0;
        for (int j = 0; j < P && !flag; j++) 
            if (ok(j, i, x)) { c[i] = 'a' + j; flag = 1; }
        if (!flag) return 0;
    }
    c[N] = '\0';
    puts(c);
    return 1;
}

void solve() {
    if (N == 1 && P == 2) { puts(s[0] == 'a' ? "b" : "NO"); return; }
    if (P == 1) { puts("NO"); return; }
    if (P == 2) { puts(s[0] == 'a' ? "ba" : "NO"); return; }
    for (int i = N - 1; i >= 0; i--)
        if (construct(i)) return;
    puts("NO");
}

int main() {
    load();
    solve();
    return 0;   
}