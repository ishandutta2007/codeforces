#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;

void load() {
    scanf("%d%d", &N, &M);
}

void solve() {
    puts(min(N, M) & 1 ? "Akshat" : "Malvika");
}

int main() {
    load();
    solve();
    return 0;
}