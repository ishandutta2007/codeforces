#include <iostream>
#include <algorithm>

using namespace std;

int g[6][6];

int get_cost(int p[]) {
    int ans = 0;
    for (int i = 1; i <= 5; ++ i) {
        for (int j = i; j + 1 <= 5; j += 2) {
            ans += g[p[j]][p[j + 1]] + g[p[j + 1]][p[j]];
        }
    }

    return ans;
}

int main()
{
    int p[6];
    for (int i = 1; i <= 5; ++ i)
        p[i] = i;

    for (int i = 1; i <= 5; ++ i)
        for (int j = 1; j <= 5; ++ j)
            cin >> g[i][j];

    int best = 0;
    do {
        int aux = get_cost(p);
        if (aux > best)
            best = aux;
    } while (next_permutation(p + 1, p + 6));

    cout << best << '\n';
    return 0;
}