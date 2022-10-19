#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 2005;

struct frac {
    ll x, y;
    frac(ll _x, ll _y) {
        x = _x;
        y = _y;
        if (y < 0) {
            x = -x;
            y = -y;
        }
        if (!y) x = 1;
    }
    bool operator <(const frac &rhs) const {
        return (ld)x * rhs.y < (ld)rhs.x * y; 
    }
};

int N;
int a[MAXN], b[MAXN], c[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d%d", a + i, b + i, c + i);
}

int choose(int n) {
    return n * (n - 1) / 2;
}

frac slope(int i, int j) {
    return frac((ll)b[i] * c[i] * (a[j] * a[j] + b[j] * b[j]) - (ll)b[j] * c[j] * (a[i] * a[i] + b[i] * b[i]),
                (ll)a[i] * c[i] * (a[j] * a[j] + b[j] * b[j]) - (ll)a[j] * c[j] * (a[i] * a[i] + b[i] * b[i]));
}

int solve() {
    ll sol = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (!c[i]) { cnt++; continue; }
        map <frac, int> occ;
        for (int j = 0; j < N; j++) 
            if (i != j && c[j]) occ[slope(i, j)]++;
        for (map <frac, int> :: iterator it = occ.begin(); it != occ.end(); it++)
            sol += (ll)choose(it -> second);
    }
    sol /= 3;
    
    if (cnt == 2) sol += (ll)(N - 2);
    return (int)sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}