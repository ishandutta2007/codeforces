#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int x[5], y[5];

void load() {
    for (int i = 0; i < 3; i++)
        scanf("%d%d", x + i, y + i);
}

int solve() {
    set <int> sx, sy;
    for (int i = 0; i < 3; i++) {
        sx.insert(x[i]);
        sy.insert(y[i]);
    }
    
    if (sx.size() == 1 || sy.size() == 1) return 1;
    if (sx.size() == 2 && sy.size() == 2) return 2;
    if (sx.size() == 3 && sy.size() == 3) return 3;
    
    if (sx.size() == 2) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    if (i != j && j != k && k != i && x[i] == x[j] && x[i] != x[k]) {
                        if (y[i] > y[j]) swap(y[i], y[j]);
                        if (y[k] > y[j] || y[k] < y[i]) return 2;
                        return 3;
                    }    
    }
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                if (i != j && j != k && k != i && y[i] == y[j] && y[i] != y[k]) {
                    if (x[i] > x[j]) swap(x[i], x[j]);
                    if (x[k] > x[j] || x[k] < x[i]) return 2;
                    return 3;
                }    
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}