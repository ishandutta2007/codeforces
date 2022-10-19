#include <cstdio>
using namespace std;

int N;

void load() {
    scanf("%d", &N);    
}

void solve() {
    if (N < 4) {
        puts("NO");
        return;
    }
    puts("YES");
    if (N > 5) {
        puts("4 * 6 = 24");
        puts("3 - 2 = 1");
        puts("1 - 1 = 0");
        for (int i = 5; i <= N; i++) 
            if (i != 6) printf("0 * %d = 0\n", i);
        puts("24 + 0 = 24");
        return;
    }    
    if (N == 5) {
        puts("5 + 3 = 8");
        puts("8 - 2 = 6");
        puts("6 * 4 = 24");
        puts("24 * 1 = 24");
        return;
    }
    if (N == 4) {
        puts("1 * 2 = 2");
        puts("2 * 3 = 6");
        puts("6 * 4 = 24");
        return;
    }
}

int main() {
    load();
    solve();
    return 0;
}