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
        int n;
        cin >> n;
        vector<int> as(n);
        int neg = 0;
        for(int &a : as) {
            cin >> a;
            if(a < 0) {
                neg ++;
            }
        }
        int cur = -1e9;
        bool fail = false;
        for(int i = 0; i < neg; i ++) {
            if(cur > -abs(as[i])) {
                fail = true;
            }
            cur = -abs(as[i]);
        }
        for(int i = neg; i < n; i ++) {
            if(cur > abs(as[i])) {
                fail = true;
            }
            cur = abs(as[i]);
        }
        cout << (fail ? "NO\n" : "YES\n");
    }
    return 0;
}