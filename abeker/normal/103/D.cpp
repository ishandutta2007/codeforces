#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 300005;
const int SQRT = 450;

int N, P;
int w[MAXN];
int a[MAXN], b[MAXN];
vector <int> Q[MAXN];
ll ans[MAXN];
    
void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", w + i);
    scanf("%d", &P);
    for (int i = 0; i < P; i++)     
        scanf("%d%d", a + i, b + i);
}

ll brute(int u, int v) {
    ll res = 0;
    for (; u <= N; u += v)
        res += w[u];
    return res;
}

void solve() {
    for (int i = 1; i < SQRT; i++) {
        for (int j = 0; j < P; j++) 
            if (b[j] == i)
                Q[a[j]].push_back(j);    
        for (int j = 0; j < i; j++) {
            ll sum = 0;
            for (int k = N - j; k > 0; k -= i) {
                sum += w[k];
                for (; !Q[k].empty(); Q[k].pop_back())
                    ans[Q[k].back()] = sum;
            }
        }
    }
    
    for (int i = 0; i < P; i++)
        printf("%I64d\n", ans[i] ? ans[i] : brute(a[i], b[i]));
}

int main() {
    load();
    solve();
    return 0;
}