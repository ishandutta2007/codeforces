#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 200010
#define P 1000000007

using namespace std;

typedef long long ll;

ll C[M], L[M], R[M];

ll powmod(ll x, ll y, ll p)
{
    ll ans = 1;
    while(y)
    {
        if(y & 1) ans = ans * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        C[k]++;
    }
    L[0] = R[200001] = 1;
    for(int i = 1; i <= 200000; i++) L[i] = L[i - 1] * (C[i] + 1) % (P - 1);
    for(int i = 200000; i >= 1; i--) R[i] = R[i + 1] * (C[i] + 1) % (P - 1);
    ll ans = 1;
    for(int i = 1; i <= 200000; i++) 
        ans = ans * powmod(i, L[i - 1] * R[i + 1] % (P - 1) * ((C[i] * (C[i] + 1) / 2) % (P - 1)) % (P - 1), P) % P;
    printf("%lld\n", ans);
    return 0;
}