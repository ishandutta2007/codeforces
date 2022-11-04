#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll X[100010], A[100010], B[100010];

vector <ll> V;

int main() {
    ll n, k;
    scanf("%lld%lld", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    for(int i = 1; i <= n; i++) scanf("%lld", &B[i]);
    for(int i = 1; i <= n; i++)
        if(X[A[i]] == 0 || B[X[A[i]]] < B[i]) X[A[i]] = i;
    for(int i = 1; i <= n; i++)
        if(X[A[i]] != i) V.push_back(B[i]);
    ll s = 0;
    for(int i = 1; i <= k; i++) if(!X[i]) s++;
    sort(V.begin(), V.end());
    ll ans = 0;
    for(int i = 0; i < s; i++) ans += V[i];
    printf("%lld\n", ans);
    return 0;
}