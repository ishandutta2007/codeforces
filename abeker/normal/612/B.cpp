#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int N;
int sec[MAXN];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int f; scanf("%d", &f);
        sec[f] = i;
    }
    
    ll sol = 0;
    for (int i = 1; i < N; i++)
        sol += (ll)abs(sec[i + 1] - sec[i]);
    
    printf("%I64d\n", sol);
    return 0;
}