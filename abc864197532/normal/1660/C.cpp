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
const int N = 200000;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = 0;
        vector <bool> vis(26, false);
        for (char c : s) {
            if (vis[c - 'a'])
                ans += 2, vis.assign(26, false);
            else
                vis[c - 'a'] = true;
        }
        cout << s.length() - ans << '\n';
    }
}