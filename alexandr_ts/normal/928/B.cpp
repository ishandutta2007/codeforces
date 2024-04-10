#include <bits/stdc++.h>
using namespace std;

void init() {
//#if __GLIBCXX__ == 20160609
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    ///freopen(TASKNAME".in", "r", stdin);
    ///freopen(TASKNAME".out", "w", stdout);
#endif
}

ostream& operator << (ostream &fo, vector<int> v) {
    for (int i = 0; i < (int)v.size(); i++)
        fo << v[i] << " ";
    return fo;
}

typedef long long ll;
const int INF = (int)1e9 + 34;
const int N = 4004;

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n), ans(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    ans[0] = min(n, k + 1);
    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            int l = max(0, i - k);
            int r = min(n - 1, i + k);
            ans[i] = r - l + 1;
            continue;
        }
        int p = a[i] - 1;
        ans[i] = ans[p];
        int l = max(p + k + 1, i - k);
        int r = min(n - 1, i + k);
        if (r >= l) ans[i] += r - l + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main() {
    init();

    int it = 1;
#ifdef FIRE_MIND
    it = 6;
#endif

    for (int i = 0; i < it; i++) {
        solve();
    }

    return 0;
}