#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 200005;

int n, k, a[MN], cnt[MN], num[MN];
vector<int> ans[MN];
ordered_set s;

int bsearch(int del) {
    int lo = 0, hi = k, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (cnt[mid] > del) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

int bsearch2(int key) {
    int lo = -1, hi = s.size() - 1, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (mid == -1) return -1;
        int val = *s.find_by_order(mid);
        if (val <= key) lo = mid;
        else hi = mid - 1;
    }
    return *s.find_by_order(lo);
}

int main() {
    boost();


    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], num[a[i]]++, s.insert(a[i]);
    //sort(a + 1, a + n + 1, greater<>());
    for (int i = 1; i <= k; i++) cin >> cnt[i];
    int del = 0, id = 1;
    while (1) {
        if (s.empty()) break;
        int maxsize = bsearch(del++);
        if (maxsize == 0) del = 0, id++, maxsize = bsearch(del++);
        //printf("maxsz: %d\n", maxsize);
        int maxhave = bsearch2(maxsize);
        if (maxhave <= 0) {del = 0, id++; continue;}
        //printf("maxhv: %d\n", maxhave);
        ans[id].push_back(maxhave);
        num[maxhave]--;
        if (num[maxhave] == 0) s.erase(maxhave);
    }
    cout << id << "\n";
    for (int i = 1; i <= id; i++) {
        cout << ans[i].size() << " ";
        for (int p : ans[i]) cout << p << " ";
        cout << "\n";
    }

    return 0;
}