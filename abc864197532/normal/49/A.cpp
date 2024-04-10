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
    string s, prev = "";
    while (cin >> s) {
        if (s.back() != '?') prev = s;
    }
    char c;
    if (s.length() == 1) c = prev.back();
    else c = s[s.length()-2];
    if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y' or c == 'A' or c == 'E' or c == 'I' or  c == 'O' or c == 'U' or c == 'Y') {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}