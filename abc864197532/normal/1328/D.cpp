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
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector <int> input(n), ans(n);
    int c = 0, s = -1;
    fop (i,0,n) cin >> input[i];
    fop (i,0,n) {
        if (input[i] == input[(i+1) % n]) {
            c++;
            s = i;
        }
    }
    if (c == n) {
        cout << "1\n";
        fop (i,0,n) cout << "1 ";
        cout << '\n';
    } else if ((n & 1) == 0) {
        cout << "2\n";
        fop (i,0,n) cout << (i & 1) + 1 << ' ';
        cout << '\n';
    } else {
        if (s == -1) {
            cout << "3\n";
            cout << "1 ";
            fop (i,1,n) {
                cout << (i & 1) + 2 << ' ';
            }
            cout << '\n';
        } else {
            cout << "2\n";
            fop (i,0,n) ans[i] = (i & 1) + 1;
            fop (i,s+1,n) ans[i] = 3 - ans[i];
            fop (i,0,n) cout << ans[i] << " \n"[i == n - 1];
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}