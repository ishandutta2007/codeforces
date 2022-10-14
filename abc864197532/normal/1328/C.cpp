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
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        string s1, s2;
        bool is = true;
        fop (i,0,n) {
            if (is and s[i] == '2') {
                s1.pb('1');
                s2.pb('1');
            }
            else if (is and s[i] == '1') {
                s1.pb('1');
                s2.pb('0');
                is = false;
            }
            else if (is and s[i] == '0') {
                s1.pb('0');
                s2.pb('0');
            } else {
                s1.pb('0');
                s2.pb(s[i]);
            }
        }
        cout << s1 << endl << s2 << endl;
    }
}