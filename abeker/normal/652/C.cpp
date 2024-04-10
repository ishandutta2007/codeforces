#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 300005;

int N, M;
int pos[MAXN];
int maks[MAXN];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        int p;
        scanf("%d", &p);
        pos[p] = i;
    }
    
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a = pos[a];
        b = pos[b];
        if (a > b) swap(a, b);
        maks[b] = max(maks[b], a);
    }
    
    ll sol = 0;
    int mx = 0;
    for (int i = 1; i <= N; i++) {
        mx = max(mx, maks[i]);
        sol += i - mx;
    }
    
    printf("%I64d\n", sol);
    
    return 0;
}