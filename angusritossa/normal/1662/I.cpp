#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, M, P[10000005], X[200005], ans, curr;

int main() {
    scanf("%lld %lld", &N, &M);
    for (ll i = 0; i < N; i++) {
        scanf("%lld", &P[i]);
    }
    for (ll i = 0; i < M; i++) {
        scanf("%lld", &X[i]);
    }
    sort(X, X+M);

    // left end
    curr = 0;
    for (ll i = 0; 100*i < X[0] && i < N; i++) {
        curr += P[i];
    }
    ans = max(ans, curr);

    // right end
    curr = 0;
    for (ll i = X[M-1]/100+1; i < N; i++) {
        curr += P[i];
    }
    ans = max(ans, curr);

    for (ll i = 0; i < M-1; i++) {
        ll l = X[i]/100+1;
        ll r = l;
        curr = P[l];
        for (; 100*l < X[i+1] && 100*r < X[i+1]; l++) {
            while (100*(r+1) - 2*100*l + X[i] < X[i+1] - 100*(r+1)) {
                curr += P[r+1];
                r++;
            }
            // printf("%lld %lld %lld %lld %lld %lld\n", l, r, curr, i, 100*r - 2*100*l + X[i], X[i+1] - 100*r);
            if (l <= r && 100*r < X[i+1]) {
                ans = max(ans, curr);
            }
            curr -= P[l];
        }
    }

    printf("%lld\n", ans);
}