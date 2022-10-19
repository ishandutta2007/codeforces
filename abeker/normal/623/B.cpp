#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

const int MAXN = 1000005;
const ll INF = (ll)1e18;

int N, A, B;
int a[MAXN];
set <int> primes;
ll val[MAXN];

void load() {
    scanf("%d%d%d", &N, &A, &B);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

void factor(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i) continue;
        primes.insert(i);
        while (!(x % i)) x /= i;
    }
    if (x > 1) primes.insert(x);
}

ll calc(int p) {
    int mini = N, maks = -1;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        val[i] = -1;
        for (int j = -1; j < 2; j++) 
            if (!((a[i] + j) % p)) 
                val[i] = (ll)abs(j) * B;
        if (val[i] == -1) {
            mini = min(mini, i);
            maks = max(maks, i);
            val[i] = 0;
        }
        sum += val[i];
        val[i] -= (ll)A;
    }   
    
    for (int i = 1; i < N; i++)
        val[i] += val[i - 1];
    
    ll mn = 0, mx = -INF;
    for (int i = 0; i < N; i++) {
        if (i < mini) mn = min(mn, val[i]);
        if (i >= maks) mx = max(mx, val[i] - mn);
    }
    
    return sum - mx;
}

ll solve() {
    for (int i = -1; i < 2; i++) {
        factor(a[0] + i);
        factor(a[N - 1] + i);
    }   
    
    ll sol = INF;
    for (set <int> :: iterator it = primes.begin(); it != primes.end(); it++)
        sol = min(sol, calc(*it));
        
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}