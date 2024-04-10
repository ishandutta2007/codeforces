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
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        set <int> nums[26];
        string ans = "";
        int n = s.length();
        if (n == 1) {
            cout << "YES" << endl;
            fop (i,0,26) cout << char('a' + i);
            cout << endl;
            continue;
        }
        fop (i,1,n) {
            nums[s[i]-'a'].insert(s[i-1]-'a');
            nums[s[i-1]-'a'].insert(s[i]-'a');
        }
        bool is = false;
        int p = -1;
        fop (i,0,26) {
            if (nums[i].size() > 2) is = true;
            else if (nums[i].size() == 1) p = i;
        }
        if (is or p == -1) {
            cout << "NO" << endl;
            continue;
        }
        bool vi[26];
        fop (i,0,26) vi[i] = false;
        while (true) {
            ans += char('a' + p);
            vi[p] = true;
            bool is2 = true;
            for (int i : nums[p]) {
                if (!vi[i]) {
                    p = i;
                    is2 = false;
                }
            }
            if (is2) break;
        }
        fop (i,0,26) {
            if (!vi[i]) ans += char('a' + i);
        }
        cout << "YES" << endl;
        cout << ans << endl;
    }
}