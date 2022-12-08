#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MOD 1000000007
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
        vector<int> bs(n);
        vector<int> cs(n);
        for(int &a : as) {
            cin >> a;
        }
        for(int &a : bs) {
            cin >> a;
        }
        for(int &a : cs) {
            cin >> a;
        }
        vector<int> locA(n+1);
        for(int i = 0; i < n; i ++) {
            locA[as[i]] = i;
        }
        int cur_cyc = 1;
        vector<int> cyc(n);
        for(int i = 0; i < n; i ++) {
            if(cyc[i]) { continue; }
            int nxt = i;
            bool odd = false;
            // cout << i << "\n";
            while(!cyc[nxt]) {
                // cout << " " << nxt << "\n";
                cyc[nxt] = cur_cyc;
                nxt = locA[bs[nxt]];
                // cout << "  -> " << nxt << "\n";
                odd = !odd;
            }
            cur_cyc ++;
        }
        vector<int> used(cur_cyc);
        for(int i = 0; i < n; i ++) {
            if(cs[i] || as[i] == bs[i]) {
                used[cyc[i]] = true;
            }
        }
        int res = 1;
        for(int i = 1; i < cur_cyc; i ++) {
            if(!used[i]) {
                res *= 2;
                res %= MOD;
            }
        } 
        cout << res << "\n";
    }
    return 0;
}