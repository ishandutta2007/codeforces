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

int main () {
    int n, m;
    cin >> n >> m;
    vector <pii> ans;
    if (n > m + 1) {
        cout << "Impossible\n";
        return 0;
    }
    fop (i,2,n+1) ans.eb(i, i - 1);
    fop (i,1,n+1) {
        if (ans.size() == m) break;
        fop (j,i+2,n+1) {
            if (ans.size() == m) break;
            if (__gcd(i, j) == 1) {
                ans.eb(i, j);
            }
        }
    }
    if (ans.size() < m) {
        cout << "Impossible\n";
    } else {
        cout << "Possible\n";
        for (pii A : ans) {
            cout << A.X << ' ' << A.Y << endl;
        }
    }
}