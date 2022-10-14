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
    cout << '\n';\
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
const int mod = 1e9 + 7, x = 864197532, N = 400008, logN = 18, K = 500, C = 100;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, id = 0;
    cin >> n;
    map <string, int> m1;
    vector <string> A;
    vector <vector <string>> S;
    set <string> has;
    fop (i,0,n) {
        string s;
        cin >> s;
        if (has.count(s)) continue;
        has.insert(s);
        string a[2];
        int f = 0;
        fop (i,7,s.length()) {
            if (!f && s[i] == '/') f = 1;
            a[f].pb(s[i]);
        }
        if (!m1.count(a[0])) {
            m1[a[0]] = id++;
            A.pb(a[0]);
            S.pb({});
        }
        S[m1[a[0]]].pb(a[1]);
    }
    id = 0;
    map <vector <string>, int> m2;
    vector <vector <int>> ans;
    fop (i,0,S.size()) {
        sort(all(S[i]));
        if (!m2.count(S[i])) {
            m2[S[i]] = id++;
            ans.pb({});
        }
        ans[m2[S[i]]].pb(i);
    }
    int anss = 0;
    fop (i,0,ans.size()) anss += ans[i].size() > 1;
    cout << anss << endl;
    fop (i,0,ans.size()) if (ans[i].size() > 1) {
        fop (j,0,ans[i].size()) {
            cout << "http://" << A[ans[i][j]] << ' ';
        }
        cout << endl;
    }
}