#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9, x = 864197532, N = 200087, logN = 17, K = 500;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    getline(cin, s);
    vector <int> a = {0};
    for (char &c : s) {
        if (c == ' ' || c == '-') a.back()++, a.pb(0);
        else a.back()++;
    }
    auto ask = [&](int w) {
        int ans = 1, tmp = 0;
        for (int i : a) {
            if (tmp + i <= w) {
                tmp += i;
            } else {
                ans++;
                tmp = i;
            }
        }
        return ans <= n;
    };
    int l = *max_element(all(a)) - 1, r = 1 << 30;
    while (r - l > 1) {
        (ask(l + r >> 1) ? r : l) = l + r >> 1;
    }
    cout << r << endl;
}