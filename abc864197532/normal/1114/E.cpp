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
#define pli pair<lli,int> 
#define X first
#define Y second

auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

int main () {
    int n, tmp;
    cin >> n;
    vector <int> aa(30);
    int t = 30;
    while (t--) {
        int k = uniform_int_distribution<int>(1, n)(rng);
        cout << "? " << k << endl;
        cin >> aa[t];
        fflush(stdout);
    }
    sort(aa.begin(), aa.end());
    int g = aa[1] - aa[0];
    fop (i,2,30) {
        g = __gcd(g, aa[i] - aa[i-1]);
    }
    int s = 0;
    FOP (i,30,0) {
        if (s + (1 << i) > 1e9) continue;
        cout << "> " << (s + (1 << i)) << endl;
        cin >> tmp;
        fflush(stdout);
        if (tmp) s += (1 << i);
    }
    cout << "! " << (s - (n - 1) * g + 1) << ' ' << g << endl;
    fflush(stdout);
}