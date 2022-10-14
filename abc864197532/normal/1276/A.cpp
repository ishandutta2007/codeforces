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
        string s;
        cin >> s;
        vector <int> nums;
        fop (i,0,s.length()) {
            if (i + 2 < s.length() and s[i] == 'o' and s[i+1] == 'n' and s[i+2] == 'e') {
                nums.pb(i+1);
                i += 2;
            }
            if (i + 2 < s.length() and s[i] == 't' and s[i+1] == 'w' and s[i+2] == 'o') {
                if (i + 4 < s.length() and s[i+3] == 'n' and s[i+4] == 'e') {
                    nums.pb(i+2);
                    i += 4;
                } else {
                    nums.pb(i+1);
                    i += 2;
                }
            }
        }
        cout << nums.size() << endl;
        fop (i,0,nums.size()) cout << nums[i]+1 << ' ' ;
        cout << endl;
    }
}