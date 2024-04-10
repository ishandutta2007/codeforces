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
    int n;
    string s;
    cin >> n >> s;
    fop (i,0,n-1) {
        if (s[i] != s[i+1]) {
            cout << "YES" << endl;
            cout << s[i] << s[i+1] << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}