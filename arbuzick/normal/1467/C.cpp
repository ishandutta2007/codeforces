#include <bits/stdc++.h>

#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
using namespace std;

bool check(int a, int b, int c) {
    return (b > a && b > c) || (b < a && b < c);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<int> a1(n1), a2(n2), a3(n3);
    int sum = 0;
    for (auto &it: a1) {
        cin >> it;
        sum += it;
    }
    for (auto &it: a2) {
        cin >> it;
        sum += it;
    }
    for (auto &it: a3) {
        cin >> it;
        sum += it;
    }
    int ans = 0;
    sort(all(a1));
    sort(all(a2));
    sort(all(a3));
    ans = sum - min(min(a1[0] + a2[0], a1[0] + a3[0]), a2[0] + a3[0]) * 2;
//    if (n1 > 1) {
//        ans = max(ans, sum - (a1[0] + a1[1]) * 2);
//    }
//    if (n2 > 1) {
//        ans = max(ans, sum - (a2[0] + a2[1]) * 2);
//    }
//    if (n3 > 1) {
//        ans = max(ans, sum - (a3[0] + a3[1]) * 2);
//    }
    int x1 = 0, x2 = 0, x3 = 0;
    for (auto it: a1) {
        x1 += it;
    }
    for (auto it: a2) {
        x2 += it;
    }
    for (auto it: a3) {
        x3 += it;
    }
    ans = max(ans, sum - x1 * 2);
    ans = max(ans, sum - x2 * 2);
    ans = max(ans, sum - x3 * 2);
    cout << ans;
    return 0;
}