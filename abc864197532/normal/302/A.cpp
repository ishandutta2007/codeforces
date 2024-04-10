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
    int n, q, l, r;
    cin >> n >> q;
    int input[n], aa = 0, bb = 0;
    fop (i,0,n) {
        cin >> input[i];
        if (input[i] == 1) aa++;
        else bb++;
    }
    int mm = min(aa, bb);
    while (q--) {
        cin >> l >> r; l--;
        if ((r - l) % 2 == 0 and mm >= (r - l) / 2) cout << 1 << endl;
        else cout << 0 << endl;
    }
}