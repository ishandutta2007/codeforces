#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
 
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        lli k;
        string s;
        cin >> n >> k >> s;
        vector <int> nums, ans(n,1);
        fop (i,0,s.length()) {
            if (s[i] == '0') nums.pb(i);
        }
        int now = 0;
        fop (i,0,nums.size()) {
            if (k >= nums[i] - now) {
                k -= (nums[i] - now);
                ans[now] = 0;
                now++;
            } else if (k) {
                ans[nums[i] - k] = 0;
                k = 0;
            } else {
                ans[nums[i]] = 0;
            }
        }
        fop (i,0,n) {
            cout << ans[i];
        }
        cout << endl;
    }
}