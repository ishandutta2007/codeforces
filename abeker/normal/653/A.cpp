#include <cstdio>
using namespace std;

const int MAXN = 1005;

bool has[MAXN];

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int t;
        scanf("%d", &t);
        has[t] = true;
    }
    
    for (int i = 0; i + 2 < MAXN; i++)
        if (has[i] && has[i + 1] && has[i + 2]) {
            puts("YES");
            return 0;
        }
    puts("NO");
    return 0;
}