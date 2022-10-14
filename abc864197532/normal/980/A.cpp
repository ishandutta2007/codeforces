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
    string s;
    cin >> s;
    int count = 0;
    fop (i,0,s.length()) {
        if (s[i] == 'o') count++;
    }
    if (count == 0) cout << "YES" << endl;
    else if (s.length() % count == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}