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
    int a, b;
    char c;
    cin >> c;
    a = c - 'a';
    cin >> c;
    b = c - '1';
    if (a == 0 and b == 0) {
        cout << 3 << endl;
    } else if (a == 7 and b == 7) {
        cout << 3 << endl;
    } else if (a == 0 and b == 7) {
        cout << 3 << endl;
    } else if (a == 7 and b == 0) {
        cout << 3 << endl;
    } else if (a == 0 or b == 0 or a == 7 or b == 7) {
        cout << 5 << endl;
    } else {
        cout << 8 << endl;
    }
    
}