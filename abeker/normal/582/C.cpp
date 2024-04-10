#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int N, K;
int a[MAXN];
int maks[MAXN];
bool f[MAXN];
int phi[MAXN];
ll sum[MAXN];
vector <int> D, F;
int mask[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

ll solve() {
    int M = N;
    for (int i = 2; i * i <= M; i++) {
        if (M % i) continue;
        while (!(M % i)) M /= i;
        F.push_back(i);
    }
    if (M > 1) F.push_back(M);
    
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < F.size(); j++)
            if (!(i % F[j])) mask[i] |= 1 << j;
            
    for (int i = 1; i <= N; i++)
        if (!(N % i)) D.push_back(i);
    
    ll sol = 0;
    K = D.size();
    for (int i = 0; i < K - 1; i++) {
        phi[0] = 0;
        sum[0] = 0;
        for (int j = 1; j <= N; j++) {
            phi[j] = phi[j - 1];
            sum[j] = sum[j - 1];
            if (mask[D[K - i - 1]] & mask[j]) continue;
            phi[j]++;
            sum[j] += (ll)j;
        }
    
        for (int j = 0; j < D[i]; j++)
            maks[j] = 0;
        for (int j = 0; j < N; j++)
            maks[j % D[i]] = max(maks[j % D[i]], a[j]);
        for (int j = 0; j < N; j++)
            f[j] = a[j] == maks[j % D[i]];
            
        vector <int> V;
        int len = 0;
        for (int j = 0; j < N; j++) {
            if (!f[j] && len) V.push_back(len);
            len = (len + 1) * f[j];
        }
        
        if (len == N) {
            sol += (ll)phi[N / D[i]] * (ll)N;
            continue;
        }
        
        if (f[N - 1]) {
            if (V.empty()) V.push_back(len);
            else if (f[0]) V[0] += len;
            else V.push_back(len);
        }
        
        for (int j = 0; j < V.size(); j++) 
            sol += (ll)phi[V[j] / D[i]] * (ll)(V[j] + 1) - (ll)D[i] * sum[V[j] / D[i]];
    }
    
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}