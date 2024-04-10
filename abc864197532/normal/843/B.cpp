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

auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

int main () {
    int n, s, x;
    cin >> n >> s >> x;
    
    int ans = -1, prev, aa, bb, q = 1000, aaa;
    
    while (q--) {
        int k = uniform_int_distribution<int>(1, n)(rng);
        if (q == 999) k = s;
        cout << "? " << k << endl;
        cin >> aa >> bb;
        if (q == 999) aaa = aa;
        fflush(stdout);
        if (aa < x) {
            if (ans < aa) {
                ans = aa;
                prev = bb;
            }
        }
    }
    
    q = 999;
    bool is = true;
    if (aaa >= x) {
        cout << "! " << aaa << endl;
        fflush(stdout);
        return 0;
    }
    
    if (prev == -1) {
        cout << "! " << -1 << endl;
        fflush(stdout);
        return 0;
    }
    
    while (q--) {
        cout << "? " << prev << endl;
        cin >> aa >> bb;
        fflush(stdout);
        if (aa >= x) {
            is = false;
            break;
        }
        if (bb == -1) break;
        prev = bb;
        
    }
    
    if (is) aa = -1;
    cout << "! " << aa << endl;
    fflush(stdout);
    return 0;
    
}