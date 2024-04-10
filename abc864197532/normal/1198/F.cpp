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
    srand(time(NULL));
    int n;
    cin >> n;
    vector <int> input(n), ans(n), id(n);
    fop (i,0,n) cin >> input[i];
    iota(id.begin(), id.end(), 0);
    while (clock() < 300) {
        random_shuffle(id.begin(), id.end());
        int x = 0, y = 0;
        fop (i,0,n) {
            int k = __gcd(x, input[id[i]]);
            if (x != 1 and k != x) {
                ans[id[i]] = 1;
                x = k;
            } else {
                ans[id[i]] = 2;
                y = __gcd(y, input[id[i]]);
            }
        }
        if (x == 1 and y == 1) {
            cout << "YES\n";
            fop (i,0,n) cout << ans[i] << " \n"[i == n - 1];
            exit(0);
        }
    }
    cout << "NO\n";
    
}