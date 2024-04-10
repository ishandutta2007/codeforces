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
    int a1 = 0;
    int a2 = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int el = arr[i];
        if (i != n - 1 && el != a1 && el != a2 && arr[i + 1] == a2) {
            a2 = el;
            ans++;
        } else if (el != a1) {
            a1 = el;
            ans++;
        } else if (el != a2) {
            a2 = el;
            ans++;
        }
    }
    cout << ans << endl;
}