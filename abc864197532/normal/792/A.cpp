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
    cin >> n;
    int a[n];
    fop (i,0,n) cin >> a[i];
    sort(a, a + n);
    int b[n-1];
    fop (i,1,n) {
        b[i-1] = a[i] - a[i-1];
    }
    sort(b, b + n - 1);
    int now = 0;
    while (true) {
        if (b[now] == b[0]) now++;
        else break;
    }
    cout << b[0] << ' ' << now << endl;
}