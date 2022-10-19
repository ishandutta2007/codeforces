#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#endif

using namespace std;

typedef long long ll;
typedef long double ldb;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    map<int, vector<int>> inds;
    for (int i = 0; i < n; i++) {
        inds[arr[i]].push_back(i);
    }
    int a1 = 0;
    int a2 = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int el = arr[i];
        if (arr[i] == a1) {

        } else if (arr[i] == a2) {

        } else {
            ans++;
            int nxt1 = n + 1;
            int nxt2 = n + 1;
            auto it = lower_bound(inds[a1].begin(), inds[a1].end(), i);
            if (it != inds[a1].end()) {
                nxt1 = *it;
            }
            auto it2 = lower_bound(inds[a2].begin(), inds[a2].end(), i);
            if (it2 != inds[a2].end()) {
                nxt2 = *it2;
            }
            if (nxt1 < nxt2) {
                a2 = el;
            } else {
                a1 = el;
            }
        }
    }
    cout << ans << endl;
}