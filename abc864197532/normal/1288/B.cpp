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

int main () {
    int t;
    cin >> t;
    while (t--) {
        int a;
        string s;
        cin >> a >> s;
        int n = s.length();
        fop (i,0,n) {
            if (s[i] != '9') {
                n--;
                break;
            }
        }
        cout << 1ll * a * n << endl;
    }
}