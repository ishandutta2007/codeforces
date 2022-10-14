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
#define MID 550
#define MAXN 300087 
int mod = 1e9 + 9;

int main () {
    int n, l = 0, r;
    string s;
    cin >> n >> s;
    r = n - 1;
    bool is = true;
    if (s[0] == s[n-1]) is = false;
    while (s[l] == s[0]) l++;
    while (s[r] == s[n-1]) r--;
    r = n - r - 1;
    if (is) {
        cout << r + l + 1 << endl;
    } else {
        cout << 1ll * (r + 1) * (l + 1) % 998244353 << endl;
    }
}