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
    string s;
    cin >> s;
    int n = s.length();
    set <int> aa, bb;
    fop (i,0,n-1) {
        if (s[i] == 'A' and s[i+1] == 'B') aa.insert(i);
        if (s[i] == 'B' and s[i+1] == 'A') bb.insert(i);
    }
    for (int i : aa) {
        bool is = false, is2 = false;
        if (bb.count(i + 1)) {
            is = true;
            bb.erase(i + 1);
        }
        if (bb.count(i - 1)) {
            is2 = true;
            bb.erase(i - 1);
        }
        if (bb.size()) {
            cout << "YES" << endl;
            return 0;
        }
        if (is) bb.insert(i + 1);
        if (is2) bb.insert(i - 1);
    }
    cout << "NO" << endl;
}