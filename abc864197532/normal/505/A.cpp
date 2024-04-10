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
    int n = s.length();
    char aa[n+1];
    fop (i,0,n+1) {
        int now = 0;
        fop (j,0,n+1) {
            if (i == j) continue;
            aa[j] = s[now];
            now++;
        }
        for (char a = 'a'; a <= 'z'; ++a) {
            aa[i] = a;
            bool is = true;
            fop (i,0,n+1) {
                if (aa[i] != aa[n - i]) {
                    is = false;
                    break;
                }
            }
            if (!is) continue;
            fop (i,0,n+1) cout << aa[i];
            cout << endl;
            return 0;
        }
    }
    cout << "NA" << endl;
}