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
        cin >> n;
        vector <string> s(n);
        int sum = 0;
        for (int i = 0; i < n; ++i)
            cin >> s[i], sum += count(all(s[i]), '1');
        int ans = 0;
        for (int r = 0; r < n; ++r) {
            int cnt = 0;
            for (int i = 0; i < n; ++i)
                cnt += s[i][(i + r) % n] == '1';
            ans = max(ans, cnt);
        }
        cout << sum - ans + n - ans << '\n';
    }
}