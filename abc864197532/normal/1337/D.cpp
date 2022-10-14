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
#define X first
#define Y second

void solve() {
    int n[3];
    cin >> n[0] >> n[1] >> n[2];
    vector <lli> num[3];
    fop (i,0,3) {
        num[i].resize(n[i]);
        fop (j,0,n[i]) cin >> num[i][j];
        sort(num[i].begin(), num[i].end());
    }
    lli ans = 1ll << 61;
    int id[3] = {0, 1, 2};
    do {
        //cout << "T" << id[0] << ' ' << id[1] << ' ' << id[2] << endl;
        fop (i,0,n[id[1]]) {
            auto it1 = lower_bound(num[id[0]].begin(), num[id[0]].end(), num[id[1]][i]);
            auto it2 = upper_bound(num[id[2]].begin(), num[id[2]].end(), num[id[1]][i]);
            if (it1 == num[id[0]].end() or it2 == num[id[2]].begin()) continue;
            --it2;
            //cout << *it1 << ' ' << num[id[1]][i] << ' ' << *it2 << endl;
            ans = min(ans, (*it1 - num[id[1]][i]) * (*it1 - num[id[1]][i]) + (*it2 - num[id[1]][i]) * (*it2 - num[id[1]][i]) + (*it1 - *it2) * (*it1 - *it2));
        }
    } while (next_permutation(id, id + 3));
    cout << ans << endl;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}