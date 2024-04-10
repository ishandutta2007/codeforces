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
#define inf 2000

int all;
string t;
vector <int> nums[26];

bool search (int a) {
    string A = "", B = "";
    fop (i,0,a) A += t[i];
    fop (i,a,t.length()) B += t[i];
    int n = A.length(), m = B.length();
    int dp[n+1][m+1];
    dp[0][0] = -1;
    fop (i,1,n+1) {
        auto it = upper_bound(nums[A[i-1] - 'a'].begin(), nums[A[i-1] - 'a'].end(), dp[i-1][0]);
        if (it == nums[A[i-1] - 'a'].end()) dp[i][0] = inf;
        else dp[i][0] = *it;
    }
    fop (i,1,m+1) {
        auto it = upper_bound(nums[B[i-1] - 'a'].begin(), nums[B[i-1] - 'a'].end(), dp[0][i-1]);
        if (it == nums[B[i-1] - 'a'].end()) dp[0][i] = inf;
        else dp[0][i] = *it;
    }
    fop (i,1,n+1) {
        fop (j,1,m+1) {
            int aa, bb;
            auto it1 = upper_bound(nums[A[i-1] - 'a'].begin(), nums[A[i-1] - 'a'].end(), dp[i-1][j]);
            auto it2 = upper_bound(nums[B[j-1] - 'a'].begin(), nums[B[j-1] - 'a'].end(), dp[i][j-1]);
            if (it1 == nums[A[i-1] - 'a'].end()) aa = inf;
            else aa = *it1;
            if (it2 == nums[B[j-1] - 'a'].end()) bb = inf;
            else bb = *it2;
            dp[i][j] = min(aa, bb);
        }
    }
    return (dp[n][m] < all);
}




void solve() {
    string s;
    cin >> s >> t;
    fop (i,0,s.length()) {
        nums[s[i] - 'a'].pb(i);
    }
    all = s.length();
    fop (i,0,t.length()+1) {
        if (search(i)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}


int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
        fop (i,0,26) nums[i].clear();
    }
}