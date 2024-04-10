#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << endl;\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200005, logN = 18, K = 600, C = 100, M = 1e9;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    fop (i,0,n) cin >> a[i];
    stack <int> stk;
    fop (i,0,n) {
        if (stk.size()) {
            if (stk.top() < a[i]) {
                cout << "NO\n";
                return 0;
            } else if (stk.top() == a[i]) stk.pop();
            else stk.push(a[i]);
        }
        else stk.push(a[i]);
    }
    while (stk.size()) stk.pop();
    FOP (i,n,0) {
        if (stk.size()) {
            if (stk.top() < a[i]) {
                cout << "NO\n";
                return 0;
            } else if (stk.top() == a[i]) stk.pop();
            else stk.push(a[i]);
        }
        else stk.push(a[i]);
    }
    if (stk.size() <= 1) cout << "YES\n";
    else cout << "NO\n";
}