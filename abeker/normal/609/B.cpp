#include <cstdio>
using namespace std;

const int MAXM = 15;

int N, M;
int cnt[MAXM];

int main() {
    scanf("%d%d", &N, &M);
    int sol = 0;
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        sol += i - cnt[x];
        cnt[x]++;
    }
    printf("%d\n", sol);
    return 0;
}