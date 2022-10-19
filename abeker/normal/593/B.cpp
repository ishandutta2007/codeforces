#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;

const int MAXN = 100005;

int N;
int lo, hi;
int k[MAXN], b[MAXN];
pii p[MAXN];

void load() {
    scanf("%d%d%d", &N, &lo, &hi);
    for (int i = 0; i < N; i++)
        scanf("%d%d", k + i, b + i);
}

bool solve() {
    for (int i = 0; i < N; i++) 
        p[i] = pii((ll)k[i] * lo + (ll)b[i], (ll)k[i] * hi + (ll)b[i]);
    
    sort(p, p + N);
    for (int i = 1; i < N; i++)
        if (p[i].first > p[i - 1].first && p[i].second < p[i - 1].second) 
            return true;
    return false;
}

int main() {
    load();
    puts(solve() ? "YES" : "NO");
    return 0;
}