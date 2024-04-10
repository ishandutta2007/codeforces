#include <cstdio>
using namespace std;

typedef long long ll;

int A, B, N;
int L, T, M;

void load() {
    scanf("%d%d%d", &L, &T, &M);
}

ll s(int x) {
    return (ll)A + (ll)(x - 1) * B;  
}

bool check(int val) {
    return (ll)(val - L + 1) * (s(L) + s(val)) / 2 <= (ll)M * T;
}

int solve() {
    int lo = L, hi = (T - A) / B + 1;
    if (lo > hi) return -1;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo; 
}

int main() {
    scanf("%d%d%d", &A, &B, &N);
    while (N--) {
        load();
        printf("%d\n", solve());
    }
    return 0;
}