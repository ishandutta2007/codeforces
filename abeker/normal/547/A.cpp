#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAXM = 1000005;

int M;
int h[5], a[5], x[5], y[5];
int tail[5], cycle[5], pos[5];
int when[MAXM];

void load() {
    scanf("%d", &M);
    for (int i = 0; i < 2; i++)
        scanf("%d%d%d%d", h + i, a + i, x + i, y + i);
}

bool check(ll t) {
    if (t < (ll)pos[1]) return 0;
    t -= (ll)pos[1];
    if (pos[1] < tail[1]) return !t;
    return !(t % (ll)cycle[1]);
}

ll solve() {
    for (int k = 0; k < 2; k++) {
        memset(when, -1, sizeof when);
        int num = h[k];
        when[num] = 0;
        pos[k] = -1;
        if (h[k] == a[k]) pos[k] = 0;
        for (int i = 1; i <= M; i++) {
            num = ((ll)x[k] * num + y[k]) % M;
            if (num == a[k] && pos[k] == -1) pos[k] = i;
            if (when[num] != -1) {
                tail[k] = when[num];
                cycle[k] = i - tail[k];
                break;
            }
            when[num] = i;
        }
    }
        
    if (pos[0] < tail[0]) 
        return check((ll)pos[0]) ? (ll)pos[0] : -1;
    for (int i = 0; i < M; i++) {
        ll tmp = (ll)i * cycle[0] + pos[0];
        if (check(tmp)) return tmp;
    }
    return -1; 
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}