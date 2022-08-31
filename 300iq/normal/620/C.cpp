#include <bits/stdc++.h>

using namespace std;

main() {
    map <int, int> f;
    int n;
    scanf("%d", &n);
    int a[n];
    vector <pair <int, int> > ans;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int l = 1;
    int r = -1;
    for (int i = 0; i < n; i++) {
        if (f[a[i]] == 0) {
            f[a[i]] = i + 1;
        }
        else {
            ans.push_back(make_pair(l, i + 1));
            r = i + 1;
            f.clear();
            l = i + 2;
        }
    }
    if (ans.size() == 0) {
        printf("%d\n", -1);
    } else {
        if (r != n) {
            ans[ans.size() - 1].second = n;
        }
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++) {
            printf("%d %d\n", ans[i].first, ans[i].second);
        }
    }

}