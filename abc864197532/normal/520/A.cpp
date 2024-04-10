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
    string s;
    cin >> s;
    int a = 0;
    bool is[26];
    fop (i,0,26) is[i] = false;
    fop (i,0,n) {
        if (s[i] >= 'a' and s[i] <= 'z') is[s[i]-'a'] = true;
        else is[s[i]-'A'] = true;
    }
    fop (i,0,26) {
        if (!is[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}