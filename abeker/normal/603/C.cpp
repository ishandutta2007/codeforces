#include <cstdio>
using namespace std;

const char name[2][10] = {"Nicky", "Kevin"};

int N, K;

int grundy(int x) {
    if (K % 2) {
        if (x < 4) return x % 2;
        if (x % 2) return 0;
        if (x < 8) return 2;
        return x % 4 ? 1 : 3 - grundy(x / 2);
    }
    return x > 2 ? !(x % 2) : x;
}

bool solve() {
    scanf("%d%d", &N, &K);
    int sol = 0;
    while (N--) {
        int x;
        scanf("%d", &x);
        sol ^= grundy(x);
    }
    return sol;
}

int main() {
    puts(name[solve()]);
    return 0;
}