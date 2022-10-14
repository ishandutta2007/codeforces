#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 1000005, logN = 17, K = 90002;

string getInput() {
    char c = getchar();
    string s;
    while (c != EOF) {
        s += c;
        c = getchar();
    }
    return s;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s = getInput(), cur;
    vector <string> order;
    string a = "\\begin{thebibliography}{99}\n", b = "\\cite{";
    vector <string> ans, p;
    int j = 0, k = 0;
    for (char c : s) {
        if (k == a.length()) {
            if (c == '\n') {
                ans.pb(cur);
                string now;
                j = 9;
                while (cur[j] != '}') now += cur[j++];
                cur.clear();
                p.pb(now);
            } else cur += c;
        } else {
            if (j == b.length()) {
                if (c == '}') order.pb(cur), cur.clear(), j = 0;
                else cur += c;
            } else {
                if (c == b[j]) j++;
                else j = 0;
                if (c == a[k]) k++;
                else k = 0;
            }
        }
    }
    ans.pop_back();
    p.pop_back();
    bool is = true;
    int n = order.size();
    fop (i,0,n) is &= order[i] == p[i];
    if (is) {
        cout << "Correct\n";
    } else {
        cout << "Incorrect\n";
        fop (i,0,n) {
            int j = 0;
            while (order[i] != p[j]) j++;
            swap(ans[i], ans[j]);
            swap(p[i], p[j]);
        }
        cout << a;
        fop (i,0,n) cout << ans[i] << endl;
        cout << "\\end{thebibliography}\n";
    }
}