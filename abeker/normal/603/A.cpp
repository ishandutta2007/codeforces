#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int N;
char s[MAXN];

void load() {
    scanf("%d%s", &N, s);
}

int solve() {
    int cnt = 1;
    int add = 0, occ = 0;
    int sol = 1;
    for (int i = 1; i < N; i++) {
        if (s[i] != s[i - 1]) {
            cnt = 0;
            sol++;
        }
        cnt++;
        if (cnt > 2) add = 2;
        else if (cnt > 1) {
            occ++;
            if (occ > 1) add = 2;
            else add = max(add, 1);
        }
    }
        
    return sol + add;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}