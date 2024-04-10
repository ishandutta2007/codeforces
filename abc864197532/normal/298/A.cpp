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
    int n;
    string s;
    cin >> n >> s;
    int l = -1, r = -1;
    fop (i,0,n) {
        if (s[i] == 'R' and r == -1) r = i;
        if (s[i] == 'L' and l == -1) l = i;
    }
    if (l != -1 and r != -1) {
        cout << r + 1 << ' ' << l << endl;
    } else if (l == -1) {
        int p = r;
        while (s[p] == 'R') {
            p++;
        }
        cout << r + 1 << ' ' << p + 1 << endl;
    } else {
        int p = l;
        while (s[p] == 'L') {
            p++;
        }
        cout << p << ' ' << l << endl;
    }
}