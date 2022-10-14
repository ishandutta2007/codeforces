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
    int n;
    cin >> n;
    vector <int> input[n];
    fop (i,0,n) {
        int tmp;
        cin >> tmp;
        input[i].resize(tmp);
        fop (j,0,tmp) cin >> input[i][j], input[i][j]--;
    }
    set <int> remain;
    fop (i,0,n) {
        remain.insert(i);
    }
    int s = -1;
    fop (i,0,n) {
        bool is = false;
        for (int j : input[i]) {
            if (remain.count(j)) {
                remain.erase(j);
                is = true;
                break;
            }
        }
        if (!is) {
            s = i;
        }
    }
    if (~s) {
        cout << "IMPROVE" << endl << s + 1 << ' ' << *remain.begin() + 1 << endl;
    } else {
        cout << "OPTIMAL" << endl;
    }
}




int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}