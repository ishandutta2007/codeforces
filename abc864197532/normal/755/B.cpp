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
    string tmp;
    set <string> aa, bb;
    fop (i,0,n) {
        cin >> tmp;
        aa.insert(tmp);
    }
    int c = 0;
    fop (i,0,m) {
        cin >> tmp;
        bb.insert(tmp);
        c += aa.count(tmp);
    }
    int now = c & 1;
    n -= c;
    m -= c;
    if (now + n <= m) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}