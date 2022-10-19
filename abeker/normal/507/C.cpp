#include <cstdio>
using namespace std;
 
typedef long long ll;

ll solve(ll pos, int h, int dir) {
    if (!h) return 0;
    ll npos = pos - (1ll << h - 1);
    if (npos > 0) return 1 + ((1ll << h) - 1) * (ll)(dir ^ 1) + solve(npos, h - 1, 0);
    return 1 + ((1ll << h) - 1) * (ll)dir + solve(pos, h - 1, 1); 
}

int main() {
    int H; ll N;
    scanf("%d%I64d", &H, &N);
    printf("%I64d\n", solve(N, H, 0));
    return 0;
}