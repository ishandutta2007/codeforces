#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,int>
#define X first
#define Y second

int main () {
    int n;
    string s;
    cin >> n >> s;
    int ans[n];
    vector <char> now;
    fop (i,0,n) {
        bool is = true;
        fop (j,0,now.size()) {
            if (now[j] <= s[i]) {
                ans[i] = j;
                now[j] = s[i];
                is = false;
                break;
            }
        }
        if (is) {
            ans[i] = now.size();
            now.push_back(s[i]);
        }
    }
    cout << now.size() << endl;
    fop (i,0,n) cout << ans[i] + 1 << " \n"[i == n - 1];
}