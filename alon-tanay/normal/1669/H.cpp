#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MOD 998244353
#define pi pair<int,int>
#define pl pair<ll,ll>
#define f first
#define s second

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> xs(n);
        for(vector<int> &vec : xs) {
            vec.resize(31);
            int x;
            cin >> x;
            for(int i = 0; i < 31; i ++) {
                vec[i] = x&1;
                x /= 2;
            }
        }
        int res = 0;
        for(int i = 30; i >= 0; i --) {
            int cnt = 0;
            for(int j = 0; j < n; j ++) {
                if(!xs[j][i]) {
                    cnt ++;
                }
            }
            if(cnt <= k) {
                k -= cnt;
                res += 1 << i;
            }
        }
        cout << res << "\n";
    }
    return 0;
}