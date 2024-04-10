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
#define endl '\n'

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        lli k = 1, now = 0;
        while (now + k < b) {
            now += k;
            k++;
        }
        string s = "";
        fop (i,0,a) s += 'a';
        s[a - k - 1]++;
        s[a - b + now]++;
        cout << s << endl;
    }
}