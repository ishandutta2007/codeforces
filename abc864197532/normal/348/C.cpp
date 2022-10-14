#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
#define endl '\n'

const int K = 316;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector <lli> input(n);
    fop (i,0,n) cin >> input[i];
    vector <set <int>> subset;
    vector <int> heavy, from_id(n, -1);
    vector <vector <int>> calc;
    vector <lli> ans_heavy;
    fop (i,0,m) {
        int tmp, aaa;
        cin >> tmp;
        set <int> aa;
        fop (j,0,tmp) cin >> aaa, aa.insert(aaa - 1);
        subset.pb(aa);
        if (tmp >= K) heavy.pb(i), from_id[i] = heavy.size() - 1;
    }
    for (int i : heavy) {
        calc.pb({});
        calc.back().resize(m, 0);
        ans_heavy.pb(0ll);
        for (int tmp : subset[i]) {
            ans_heavy.back() += input[tmp];
        }
        fop (j,0,m) {
            for (int tmp : subset[j]) {
                if (subset[i].count(tmp)) calc.back()[j]++;
            }
        }
    }
    char c;
    int x, y;
    vector <lli> lazy(heavy.size(), 0);
    while (q--) {
        cin >> c >> x;
        x--;
        if (c == '?') {
            if (from_id[x] == -1) {
                lli ans = 0;
                for (int j : subset[x]) ans += input[j];
                fop (i,0,heavy.size()) {
                    ans += lazy[i] * calc[i][x];
                }
                cout << ans << endl;
            } else {
                cout << ans_heavy[from_id[x]] << endl;
            }
        } else {
            cin >> y;
            if (from_id[x] == -1) {
                for (int j : subset[x]) input[j] += y;
                fop (i,0,heavy.size()) {
                    ans_heavy[i] += 1ll * calc[i][x] * y;
                }
            } else {
                lazy[from_id[x]] += y;
                fop (i,0,heavy.size()) {
                    ans_heavy[i] += 1ll * calc[i][x] * y;
                }
            }
        }
    }
}