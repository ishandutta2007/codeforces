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

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string input[n];
    int r[n], c[m], all = 0;
    fop (i,0,n) r[i] = 0;
    fop (i,0,m) c[i] = 0;
    fop (i,0,n) {
        cin >> input[i];
        fop (j,0,m) {
            if (input[i][j] == '*') {
                r[i]++;
                c[j]++;
                all++;
            }
        }
    }
    fop (i,0,n) {
        fop (j,0,m) {
            if (r[i] + c[j] - (input[i][j] == '*') == all) {
                cout << "YES\n";
                cout << i + 1 << ' ' << j + 1 << endl;
                return 0;
            }
        }
    }
    cout << "NO\n";
}