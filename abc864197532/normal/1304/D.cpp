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

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int minn[n], maxx[n];
    fop (i,0,n) minn[i] = n - i, maxx[i] = i + 1;
    for (int i = 0, j = 0; i < n - 1; i = j) {
        while (j < n - 1 and s[i] == s[j]) j++;
        if (s[i] == '<') reverse(minn + i, minn + j + 1);
        else reverse(maxx + i, maxx + j + 1);
    }
    fop (i,0,n) cout << minn[i] << " \n"[i == n - 1];
    fop (i,0,n) cout << maxx[i] << " \n"[i == n - 1];
}

int main () {
    int t;
    cin >> t;
    while (t--) solve();
}