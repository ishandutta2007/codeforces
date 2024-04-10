#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int N;
int x[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", x + i);
}

bool solve() {
    for (int i = 1; i < N; i++)
        for (int j = 1; j < N; j++) {
            int a = x[i], b = x[i - 1];
            int c = x[j], d = x[j - 1];
            if (a > b) swap(a, b);
            if (c > d) swap(c, d);
            if ((a < c && c < b && b < d) || (c < a && a < d && d < b))
                return 1;
        }
    return 0;
}

int main() {
    load();
    puts(solve() ? "yes" : "no");
    return 0;
}