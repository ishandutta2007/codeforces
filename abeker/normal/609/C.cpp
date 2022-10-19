#include <cstdio>
#include <algorithm>
#include <functional>
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
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += a[i];
    
    sort(a, a + N, greater <int>());
    int sol = 0;
    for (int i = 0; i < N; i++) 
        sol += abs(sum / N + (i < sum % N) - a[i]);
    return sol / 2;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}