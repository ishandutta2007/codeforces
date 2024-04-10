#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int a = 0, b = 0, c = 0, d = 0;
        fop (i,0,s.length()) {
            if (s[i] == 'D') a++;
            else if (s[i] == 'U') b++;
            else if (s[i] == 'L') c++;
            else d++;
        }
        int aa = min(a,b);
        int bb = min(c,d);
        if (aa > 0 and bb > 0) {
            cout << 2 * (aa + bb) << endl;
            fop (i,0,aa) cout << 'D';
            fop (i,0,bb) cout << 'L';
            fop (i,0,aa) cout << 'U';
            fop (i,0,bb) cout << 'R';
            cout << endl;
        } else if (aa > 0) {
            cout << 2 << endl << "DU" << endl;
        } else if (bb > 0) {
            cout << 2 << endl << "LR" << endl;
        } else {
            cout << 0 << endl;
        }
    }
}