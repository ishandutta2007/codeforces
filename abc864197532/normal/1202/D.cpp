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
const int MOD = 1e9 + 7;
const int N = 2020;

void solve() {
    int n;
    cin >> n;
    int x = 0, i = 1;
    while (x + i <= n) {
        x += i;
        i++;
    }
    string s = "1";
    fop (j,0,i-2) s += '3';
    fop (j,0,n-x) s += '1';
    s += "337";
    cout << s << endl;
}

int main () {
    int t;
    cin >> t;
    while (t--) solve();
}