#include <cstdio>
using namespace std;

typedef long double ld;

const int MAXN = 100005;

int N, P;
ld prob[MAXN];

int main() {
    scanf("%d%d", &N, &P);
    for (int i = 0; i < N; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        prob[i] = (ld)(r / P - (l - 1) / P) / (r - l + 1);
    }
    
    ld sol = 0;
    for (int i = 0; i < N; i++)
        sol += prob[i] * (2 - prob[(i + 1) % N]);
    
    printf("%lf\n", (double)sol * 2000);
    return 0;
}