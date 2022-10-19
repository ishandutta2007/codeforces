#include <cstdio>
#include <vector>
using namespace std;

int N;
vector <int> sol;

void load() {
    scanf("%d", &N);
}

bool prime(int x) {
    for (int i = 2; i < x; i++)
        if (!(x % i)) return false;
    return true;
}

void solve() {
    if (N == 1) {
        puts("0");
        return;
    }
    for (int i = 2; i <= N; i++) {
        if (!prime(i)) continue;
        for (int x = i; x <= N; x *= i)
            sol.push_back(x);
    }
    printf("%d\n", sol.size());
    for (int i = 0; i < sol.size(); i++)
        printf("%d ", sol[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}