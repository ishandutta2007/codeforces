#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

typedef long long lint;

using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int n, d, a, b;
//    cin >> n >> d >> a >> b;
    scanf("%d%d%d%d", &n, &d, &a, &b);

    vector< pair<int, int> > c;
    for (int i = 0; i < n; ++i) {
        int x, y;
//        cin >> x >> y;
        scanf("%d%d", &x, &y);
        c.push_back({x * a + y * b, i});
    }
    sort(c.begin(), c.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i].first > d) {
            break;
        }
        ans++;
        d -= c[i].first;
    }
//    cout << ans << "\n";
    printf("%d\n", ans);
    for (int i = 0; i < ans; ++i) {
//        cout << c[i].second + 1 << " ";
        printf("%d ", c[i].second + 1);
    }

    return 0;
}