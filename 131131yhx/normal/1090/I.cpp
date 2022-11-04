#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1ll << 32;

ll A[10000010], n, l, r, x, y, z, b1, b2;

ll btoa(ll x) {return x % (r - l + 1) + l;}

//int L[10000010], R[10000010], F[10000010];

void Solve() {
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &n, &l, &r, &x, &y, &z, &b1, &b2);
    A[1] = b1, A[2] = b2;
    for(int i = 3; i <= n; i++) A[i] = (A[i - 2] * x + A[i - 1] * y + z) & ((1ll << 32) - 1);
    for(int i = 1; i <= n; i++) A[i] = btoa(A[i]);
    /*int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);*/
    ll mx = -1, ans = 5e18;
    for(int i = n; i >= 1; i--) {
        if(A[i] <= 0 && mx != -1) ans = min(ans, mx * A[i]);
        if(A[i] >= 0) mx = max(mx, A[i]);
    }
    vector <int> V(0);
    ll mn = A[1];
    for(int i = 2; i <= n; i++) {
        if(A[i] >= 0 && mn < A[i]) ans = min(ans, mn * A[i]);
        mn = min(mn, A[i]);
    }
    V.clear();
    for(int i = 1; i <= n; i++)
        if(A[i] <= 0) {
            while(!V.empty() && A[i] > A[V.back()]) V.pop_back();
            V.push_back(i);
        }
    for(int i = 0; i < V.size(); i++) {
        int x = V[i], o = (i == 0 ? 1 : V[i - 1] + 1);
        for(int j = o; j < x; j++)
            if(A[j] < A[x]) ans = min(ans, A[j] * A[x]);
    }
    if(ans == 5e18) {
        puts("IMPOSSIBLE");
        return;
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        Solve();
    }
    return 0;
}