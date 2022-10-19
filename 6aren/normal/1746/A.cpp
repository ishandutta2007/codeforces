#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include<cp/debugger.hpp>
#else 
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int sum = 0;
        for (int &e : a) cin >> e, sum += e;
        if (sum == 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    } 
    return 0;
}