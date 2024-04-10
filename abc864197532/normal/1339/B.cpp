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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int input[n];
        fop (i,0,n) cin >> input[i];
        sort(input, input + n);
        vector <int> ans(n);
        fop (i,0,n / 2) {
            ans[i * 2] = i;
            ans[i * 2 + 1] = n - 1 - i;
        }
        if (n & 1) ans[n - 1] = n / 2;
        FOP (i,n,0) cout << input[ans[i]] << ' ';
        cout << '\n';
    }
}