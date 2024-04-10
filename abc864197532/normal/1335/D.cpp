#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,lli>
#define X first
#define Y second
const int mod = 998244353;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n = 9, pos[9] = {0, 3, 6, 1, 4, 7, 2, 5, 8};
    while (t--) {
        string input[n];
        fop (i,0,n) cin >> input[i];
        fop (i,0,n) {
            if (input[i][pos[i]] == '1') input[i][pos[i]] = '2';
            else input[i][pos[i]] = '1';
        }
        fop (i,0,n) cout << input[i] << '\n';
    }
}