#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000005;

int N, M;
int dx, dy;
int cnt[MAXN];

inline int add(int x, int y) { return (x + y) % N; }
inline int mul(int x, int y) { return (long long)x * y % N; }

int main() {
    scanf("%d%d%d%d", &N, &M, &dx, &dy);
    for (int i = 1; i < N; i++) 
        if (mul(dy, i) == N - 1) {
            dx = mul(dx, i);
            break;
        } 
    while (M--) {
        int x, y;
        scanf("%d%d", &x, &y);
        cnt[add(x, mul(dx, y))]++;
    }
    printf("%d 0\n", max_element(cnt, cnt + N) - cnt);
    return 0;    
}