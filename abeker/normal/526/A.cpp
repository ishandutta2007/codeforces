#include <cstdio>
using namespace std;

const int MAXN = 105;

int N;
char s[MAXN];

void load() {
    scanf("%d%s", &N, s);
}

bool solve() {
    for (int i = 0; i < N; i++) 
        for (int j = 1; i + 4 * j < N; j++) {
            bool ok = true;
            for (int k = 0; k < 5; k++)
                ok &= s[i + k * j] == '*';
            if (ok) return true;
        }
    return false;
}

int main() {
    load();
    puts(solve() ? "yes" : "no");
    return 0;
}