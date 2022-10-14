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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> input(n);
        fop (i,0,n) cin >> input[i];
        int prime[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int ans[n], count[11];
        fop (i,0,11) count[i] = 0;
        fop (i,0,n) {
            fop (j,0,11) {
                if (input[i] % prime[j] == 0) {
                    ans[i] = j;
                    count[j]++;
                    break;
                }
            }
        }
        int neww[11];
        int cc = 0;
        fop (i,0,11) if (count[i]) neww[i] = cc++;
        cout << cc << endl;
        for (int i : ans) cout << neww[i] + 1 << ' ';
        cout << '\n';
    }
}