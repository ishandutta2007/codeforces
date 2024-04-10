#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100005;

char s[MAXN];

void load() {
    scanf("%s", s);
}

int pow(int a, int b) {
    int c = 1;
    while (b--) c *= a;
    return c;
}

int solve() {
    int N = strlen(s), e = 0, sol = 0;
    for (int i = 0; i < N; i++) 
        e = (10 * e + s[i] - '0') % 4;
    for (int i = 1; i <= 4; i++) 
        sol = (sol + pow(i, e)) % 5;
    return sol;        
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}