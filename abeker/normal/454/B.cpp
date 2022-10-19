#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int N;
int a[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d", a + i);
}

int solve() {
    int mini = *min_element(a, a + N);
    int lo, hi, pos;
    for (lo = 0; lo < N && a[lo] == mini; lo++);
    for (hi = N - 1; hi >= 0 && a[hi] == mini; hi--);
    if (lo == N) return 0;
    if (!lo && hi == N - 1) {
        for (int i = 0; i < N; i++) 
            if (a[i] == mini) { pos = i; break; }
    }
    if (!lo && hi < N - 1) pos = ++hi;
    if (lo && hi == N - 1) pos = 0;
    if (lo && hi < N - 1) pos = ++hi;
    for (int j = 0; j < N - 1; j++) 
        if (a[(pos + j) % N] > a[(pos + j + 1) % N]) return -1;
    return (N - pos) % N; 
}
    
int main() {
    load();
    printf("%d\n", solve());
    return 0;
}