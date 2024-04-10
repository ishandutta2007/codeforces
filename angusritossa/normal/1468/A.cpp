#include <bits/stdc++.h>
using namespace std;
int a[500010];
int best[500010], n, saved[500010];
int bsearch(int val) {
    int s = 0;
    int e = n;
    while (s != e) {
        int m = (s+e+1)/2;
        if (best[m] > val) {
            e = m-1;
        } else {
            s = m;
        }
    }
    return s;
}
vector<int> toCheck[500010];
int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) {
            toCheck[i].clear();
            best[i] = 1e9;
            saved[i] = -1;
        }
        best[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        a[0] = 1e9;
        stack<int> s;
        s.push(0);
        for (int i = 1; i <= n; i++) {
            while (a[s.top()] < a[i]) s.pop();
            toCheck[s.top()].push_back(i);
            //printf("%d: %d\n", i, s.top());
            s.push(i);
        }
        for (int i = 1; i <= n; i++) {
            int am = bsearch(a[i]);
            //printf("%d: %d %d\n", i, am, saved[i]);
            for (auto j : toCheck[i]) {
                saved[j] = bsearch(a[j]);
            }
            best[am+1] = min(best[am+1], a[i]);
            best[saved[i]+2] = min(best[saved[i]+2], a[i]);
        }
        int ans = bsearch(n);
        printf("%d\n", ans);
    }
}