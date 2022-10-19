#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);

    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n + 2);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<vector<int>> pos(n + 2, vector<int>(0));
        for (int i = 1; i <= n; i++) pos[a[i]].push_back(i);
        vector<int> ans(n + 5, 0);
        
        set<int> s;
        s.insert(0);
        s.insert(n + 1);

        for (int i = 1; i <= n; i++) {
            int mx = 0;
            for (int e : pos[i]) {
                auto lowerIt = s.lower_bound(e);
                lowerIt--;
                int lower = *lowerIt;
                auto upperIt = s.upper_bound(e);
                int upper = *upperIt;
                mx = max(mx, upper - lower - 1);
            }
            for (int e : pos[i]) s.insert(e);
            mx = min(mx, n - i + 1);
            ans[1]++;
            ans[mx + 1]--;
        }
        
        for (int i = 2; i <= n; i++) ans[i] += ans[i - 1];
        
        for (int i = 1; i <= n; i++) cout << (ans[i] == n + 1 - i);
        cout << '\n';
        
    }

    return 0;
}