#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 105;
int p[MAXN];

int get(int x) {
    int pos = 0;
    while(p[pos] != x)
        pos++;
    rotate(p, p + pos, p + pos + 1);
    return pos + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
        cin >> p[i];
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            int a;
            cin >> a;
            ans += get(a);
        }
    cout << ans << '\n';
    return 0;
}