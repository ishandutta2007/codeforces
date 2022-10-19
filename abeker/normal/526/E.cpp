#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 2000005;

int N, Q;
int a[MAXN];
int nxt[MAXN], prev[MAXN];
int pref[MAXN], suff[MAXN];
int lo[MAXN], hi[MAXN];

void load() {
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

void solve() {
    ll tot = 0;
    for (int i = 0; i < N; i++) {
        a[i + N] = a[i];
        tot += (ll)a[i];
    }
        
    while (Q--) {
        ll B;
        scanf("%I64d", &B);
        if (tot <= B) {
            puts("1");
            continue;
        }
        
        int j = -1;
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            if (sum <= B) 
                for (++j; ; j++) {
                    sum += (ll)a[j];
                    if (sum > B) break;
                }
            nxt[i] = j;
            sum -= (ll)a[i];
        }
        
        j = 2 * N;
        sum = 0;
        for (int i = 2 * N - 1; i >= N; i--) {
            if (sum <= B) 
                for (--j; ; j--) {
                    sum += (ll)a[j];
                    if (sum > B) break;
                }
            prev[i] = j;
            sum -= (ll)a[i];
        }
        
        for (int i = 0; i < N; i++)
            lo[i + N] = i + N;
        for (int i = N - 1; i >= 0; i--) {
            suff[i] = suff[nxt[i]] + 1;
            lo[i] = lo[nxt[i]];
        }
        
        for (int i = N; i < 2 * N; i++) 
            if (prev[i] < N) {
                pref[i] = 0;
                hi[i] = i;
            }
            else {
                pref[i] = pref[prev[i]] + 1;
                hi[i] = hi[prev[i]];
            }
        
        
        int sol = N;
        for (int i = 0; i < N; i++) 
            if (lo[i] >= i + N) sol = min(sol, suff[i]);
            else sol = min(sol, suff[i] + pref[i + N] + (lo[i] <= hi[i + N]));
        printf("%d\n", sol);
    }
}

int main() {
    load();
    solve();
    return 0;
}