#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 200005;

int N, M;
int a[MAXN], b[MAXN];
int t[MAXN], r[MAXN];
vector <int> V;

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
    for (int i = 0; i < M; i++)
        scanf("%d%d", t + i, r + i);        
    
    int pos = M;
    V.push_back(M);
    for (int i = M - 1; i >= 0; i--)
        if (r[i] > r[pos]) {
            V.push_back(i);
            pos = i;
        }
    
    for (int i = 0; i < N; i++)
        b[i] = a[i];
        
    int lo = 0, hi = r[V.back()];
    sort(a, a + hi);
    for (int i = (int)V.size() - 1; i; i--) {
        for (int j = r[V[i - 1]]; j < r[V[i]]; j++)
            b[j] = t[V[i]] == 1 ? a[hi - r[V[i]] + j] : a[lo + r[V[i]] - j - 1];   
        if (t[V[i]] == 1) hi = lo + r[V[i - 1]];
        else lo = hi - r[V[i - 1]];
    }
    
    for (int i = 0; i < N; i++)
        printf("%d ", b[i]);
    puts("");
    
    return 0;
}