#include <bits/stdc++.h>
using namespace std;
const int MN = 55;
int n, a[MN][MN];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) continue;
            vector<int> x, y;
            for (int k = 1; k <= n; k++) {
                if (k != i) x.push_back(a[k][j]);
                if (k != j) y.push_back(a[i][k]);
            }
            bool meme = 0;
            for (int p1 : x) for (int p2 : y) if (p1 + p2 == a[i][j]) meme = 1;
            if (!meme) return 0 * printf("No\n");
        }
    }
    printf("Yes\n");
}