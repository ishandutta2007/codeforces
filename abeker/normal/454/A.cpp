#include <cstdio>
using namespace std;

int N;

void load() {
    scanf("%d", &N);
}

void solve() {
    int a = N / 2, b = 1, c = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < a; j++) putchar('*');
        for (int j = 0; j < b; j++) putchar('D');
        for (int j = 0; j < a; j++) putchar('*');
        if (i == N / 2) c = -1;
        a -= c;
        b += 2 * c;
        puts("");
    }
}

int main() {
    load();
    solve();
    return 0;
}