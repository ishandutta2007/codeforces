#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

map <int, int> X, Y;
map <pii, int> cnt;

int main() {
    int N;
    scanf("%d", &N);
    ll sol = 0;
    while (N--) {
        int x, y;
        scanf("%d%d", &x, &y);
        sol += X[x]++;
        sol += Y[y]++;
        sol -= cnt[pii(x, y)]++;
    }
    printf("%I64d\n", sol);
    return 0;
}