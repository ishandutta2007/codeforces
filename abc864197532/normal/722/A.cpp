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
    int a, b, c;
    cin >> a;
    string s;
    cin >> s;
    b = (s[0] - '0') * 10 + (s[1] - '0');
    c = (s[3] - '0') * 10 + (s[4] - '0');
    if (a == 12) {
        if (1 <= b and b <= 12) {
            
        } else {
            if (b == 0) b = 1;
            else if (b % 10 == 0) b = 10;
            else b %= 10;
        }
        if (0 <= c and c < 60) {
            
        } else {
            c %= 10;
        }
    } else {
        if (0 <= b and b < 24) {
            
        } else {
            b %= 10;
        }
        if (0 <= c and c < 60) {
            
        } else {
            c %= 10;
        }
    }
    if (b / 10 == 0) cout << 0;
    cout << b << ':';
    if (c / 10 == 0) cout << 0;
    cout << c << "\n";
}