#include <cstdio>
using namespace std;

const int MAXN = 105;

bool bio[MAXN];

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int cnt = 0;
    while (N--) {
        int x;
        scanf("%d", &x);
        while (x--) {
            int y;
            scanf("%d", &y);
            if (bio[y]) continue;
            bio[y] = true;
            cnt++;            
        }
    }
    puts(cnt == M ? "YES" : "NO");
    return 0;
}