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
    bool is2 = true;
    char now1 = 0, now2 = 0;
    fop (i,0,n) {
        if (s[i] >= now1) {
            ans[i] = 0;
            now1 = s[i];
        } else {
            if (s[i] >= now2) {
                ans[i] = 1;
                now2 = s[i];
            } else {
                is2 = false;
                break;
            }
        }
    }
    if (!is2) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        fop (i,0,n) cout << ans[i];
        cout << endl;
    }
}