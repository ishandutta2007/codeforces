#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    set <int> X, Y;
    while (N--) {
        int x, y;
        scanf("%d%d", &x, &y);
        X.insert(x);
        Y.insert(y);
    }
    printf("%d\n", min(X.size(), Y.size()));
    return 0;
}