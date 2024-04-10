#include <cstdio>
using namespace std;

bool check(int mass, int weight) {
    if (!mass) return true;
    for (int i = -1; i < 2; i++)
        if (!((mass + i) % weight)) 
            return check((mass + i) / weight, weight);
    return false;
}

int main() {
    int W, M;
    scanf("%d%d", &W, &M);
    puts(check(M, W) ? "YES" : "NO");
    return 0;
}