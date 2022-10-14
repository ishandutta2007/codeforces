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
        string s1,s2;
        cin >> s1 >> s2;
        if (s1.length() > s2.length()) {
            cout << "NO" << endl;
            continue;
        }
        bool is = false;
        sort(s1.begin(), s1.end());
        fop (i,0,s2.length() - s1.length() + 1) {
            string a = "";
            fop (j,i,s1.length() + i) {
                a += s2[j];
            }
            sort(a.begin(), a.end());
            if (a == s1) {
                is = true;
                break;
            }
        }
        if (is) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}