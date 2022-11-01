#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld PI = acos(-1);
const ll MAX = 1e6 + 10;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 1e6 + 10;



pair <int, int> solve(int l, int r) {
    if (l == r)
        return mp(l, r);
    int len = r - l + 1;
    int cur = 1;
    while (cur * 2 < len)
        cur *= 2;
    auto t1 = solve(l, l + cur - 1);
    auto t2 = solve(l + cur, r);

    cout << "? " << t1.first + 1 << " " << t2.first + 1 << endl;
    char ch;
    cin >> ch;
    pair <int, int> ans;
    if (ch == '<')
        ans.first = t1.first;
    else
        ans.first = t2.first;
    if (len == 2) {
        if (ch == '<')
            ans.second = t2.first;
        else
            ans.second = t1.first;
    }
    if (len > 2) {
        cout << "? " << t1.second + 1 << " " << t2.second + 1 << endl;
        cin >> ch;
        if (ch == '>')
            ans.second = t1.second;
        else
            ans.second = t2.second;
    }
    return ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto ans = solve(0, n - 1);
        cout << "! " << ans.first + 1 << " " << ans.second + 1 << endl;
    }
    return 0;
}