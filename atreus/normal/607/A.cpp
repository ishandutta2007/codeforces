#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 500;
set <int> s;
map <int, int> mp, dp;
int a[maxn];

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int b;
        cin >> a[i] >> b;
        mp[a[i]] = b;
        s.insert(a[i]);
    }
    sort (a, a + n);
    for (int i = 0; i < n; i++){
        set<int>::iterator it;
        it = s.lower_bound(a[i] - mp[a[i]]);
        if (it == s.begin())
            dp[a[i]] = 1;
        else{
            it --;
            int x = *it;
            dp[a[i]] = dp[x] + 1;
        }
    }
    int k = 0;
    for (int i = 0; i < n; i++){
        k = max(k, dp[a[i]]);
    }
    cout << n - k << endl;
}