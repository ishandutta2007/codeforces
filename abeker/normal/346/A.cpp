#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int maks = 0, d = 0;
    for (int i = 0; i < N; i++) {
        int x; scanf("%d", &x);
        maks = max(maks, x);
        d = __gcd(d, x);
    }
    puts((maks / d - N) % 2 ? "Alice" : "Bob");
    return 0;
}