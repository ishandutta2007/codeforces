#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

int N;
int a[MAXN];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d", a + i);
    ll sol = 0;
    for (int i = 0; i < N; i++) {
        int b;
        scanf("%d", &b);
        if (2 * a[i] < b || b == 1) sol--;
        else sol += (ll)min(b / 2, a[i]) * (b - min(b / 2, a[i])); 
    }
    printf("%I64d\n", sol);
    return 0;
}