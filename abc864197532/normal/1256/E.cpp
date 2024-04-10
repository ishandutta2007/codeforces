#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>
vector <pii> nums;
lli dp[200000][2];

lli dpp (int a) {
    if (a == nums.size()) return 0;
    if (dp[a][0] != -1) return dp[a][0];
    dp[a][0] = LLONG_MAX;
    fop (i,3,6) {
        if (i + a > nums.size() - 3 and i + a != nums.size()) continue;
        lli tmp = dpp(i+a) + nums[i+a-1].first - nums[a].first;
        if (dp[a][0] > tmp) {
            dp[a][0] = tmp;
            dp[a][1] = i;
        }
    }
    return dp[a][0];
}

int main () {
    int n, tmp;
    cin >> n;
    fop (i,0,n) {
        dp[i][0] = -1;
        cin >> tmp;
        nums.eb(tmp, i);
    }
    sort(nums.begin(), nums.end());
    cout << dpp(0) << ' ';
    int ans[n];
    int now = 0, k = 1;
    while (now < n) {
        fop (i,now,now+dp[now][1]) {
            ans[nums[i].second] = k;
        }
        now += dp[now][1];
        k++;
    }
    cout << k-1 << endl;
    fop (i,0,n) cout << ans[i] << " \n"[i==n-1];
}