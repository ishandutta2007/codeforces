#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int N;
int b[MAXN];

int main() {
    scanf("%d", &N);
    ll sol = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", b + i);
        sol += (ll)abs(b[i] - b[i - 1]);
    }
    printf("%I64d\n", sol); 
    return 0;
}