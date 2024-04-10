#include <bits/stdc++.h>
using namespace std;
int keep[200010];
int largestBefore[200010];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k, m;
        scanf("%d%d%d", &n, &k, &m);
        fill_n(keep, n+1, 0);
        k /= 2;
        for (int i = 0; i < m; i++) {
            int a;
            scanf("%d", &a);
            keep[a] = true;
        }
        int sz = 0;
        int l = 0;
        vector<pair<int, int> > segments;
        for (int i = 1; i <= n; i++) {
            if (!keep[i]) {
                if (!sz) {
                    l = i;
                }
                sz++;
                if (sz == k) {
                    int r = i;
                    segments.push_back({l, r});
                }
                sz %= k;
                largestBefore[i] = largestBefore[i-1];
            } else {
                largestBefore[i] = i;
            }
        }
        if (sz || segments.size()%2) {
            printf("NO\n");
            continue;
        }
        int len = segments.size();
        len /= 2;
        bool good = false;
        for (int i = 0; i < len; i++) {
            if (!(largestBefore[segments[i+len].first] < segments[i].second)) {
                good = true;
            }
        }
        if (!good) printf("No\n");
        else printf("YES\n");

    }
}