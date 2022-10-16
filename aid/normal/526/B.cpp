#include <iostream>

using namespace std;

const int MAXN = 15, POWN = (1 << MAXN);
int a[POWN], d[POWN];

int dfs(int v, int n) {
    if(n == 0) {
        d[v] = a[v];
        return 0;
    }
    int res = dfs(2 * v, n - 1) + dfs(2 * v + 1, n - 1);
    res += max(d[2 * v], d[2 * v + 1]) - min(d[2 * v], d[2 * v + 1]);
    d[v] = max(d[2 * v], d[2 * v + 1]) + a[v];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 2; i <= (1 << (n + 1)) - 1; i++)
        cin >> a[i];
    cout << dfs(1, n) << '\n';
    return 0;
}