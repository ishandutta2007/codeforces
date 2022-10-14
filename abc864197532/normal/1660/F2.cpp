#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define X first
#define Y second
#define all(x) x.begin(), x.end()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T i, U ...j) {
    cout << i << ' ', abc(j...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l)
        cout << *l << " \n"[l + 1 == r];
}
#ifdef Doludu
#define test(x...) abc("[" + string(#x) + "]", x)
#define owo freopen("input.txt", "r", stdin)
#else
#define test(x...) void(0)
#define owo ios::sync_with_stdio(false), cin.tie(0)
#endif
const int N = 200087;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector <int> pre(n + 1, 0);
        for (int i = 0; i < n; ++i)
            pre[i + 1] = pre[i] + (s[i] == '-' ? 1 : -1);
        // i < j, pre[i] <= pre[j], pre[j] % 3 == pre[i] % 3;
        lli ans = 0;
        vector <int> bit((n << 1) + 5, 0);
        auto add = [&](int p, int v) {
            p += n + 3;
            for (; p < (n << 1) + 5; p += p & (-p))
                bit[p] += v;
        };
        auto query = [&](int p) {
            int ans = 0;
            p += n + 3;
            for (; p > 0; p -= p & (-p))
                ans += bit[p];
            return ans;
        };
        for (int r = 0; r < 3; ++r) {
            bit.assign((n << 1) + 5, 0);
            for (int i = 0; i <= n; ++i) if ((pre[i] % 3 + 3) % 3 == r) {
                ans += query(pre[i]);
                add(pre[i], 1);
            }
        }
        cout << ans << '\n';
    }
}