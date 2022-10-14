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
    bool is = false;
    string ans;
    vector <int> v;
    v.pb(-2);
    fop (i,0,s.length()) {
        ans.pb(s[i]);
        if (s[i] == '@') {
            is = true;
            v.pb(i);
        } else {
            if (is) {
                is = false;
                ans.pb(',');
            }
        }
    }
    v.pb(s.length() + 1);
    is = true;
    fop (i,1,v.size()) {
        if (v[i] - v[i - 1] <= 2) {
            is = false;
        }
    }
    if (v.size() == 2) is = false;
    if (!is) cout << "No solution\n";
    else {
        string noo;
        int c = 0;
        FOP (i,ans.length(), 0) {
            if (ans[i] == ',' and c == 0) {
                c++;
            } else {
                noo.pb(ans[i]);
            }
        }
        reverse(noo.begin(), noo.end());
        cout << noo;
        
    }
}