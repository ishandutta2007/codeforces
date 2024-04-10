//#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef long double ldb;

vector<int> arr;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    set<pair<int, int>> s;
    for (int i = 0; i <= k; i++) {
        s.insert({-0, i});
    }
    vector<int> sum(k + 1);
    int ans = 0;
    for (int el : arr) {
        auto pp = *s.begin();
        s.erase(s.begin());
        ans += sum[pp.second];
        sum[pp.second] += el;
        s.insert({-sum[pp.second], pp.second});
    }
    cout << ans << endl;
}