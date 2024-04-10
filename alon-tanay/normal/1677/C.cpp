#include <bits/stdc++.h>
#define ll long long
#define pl pair<ll,ll>
#define pi pair<int,int>
#define f first
#define s second
#define vi vector<int>
#define vl vector<ll>
#define ld long double

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
        vector<int> loc(n);
        int idx = 0;
        for(int &a : as) {
            cin >> a; a --;
            loc[a] = idx ++;
        }
        for(int &a : bs) {
            cin >> a; a --;
        }
        vector<int> vis(n);
        vector<int> cyc;
        for(int i = 0; i < n; i ++) {
            if(vis[i]) { continue; }
            int nxt = i;
            int sz = 0;
            while(!vis[nxt]) {
                vis[nxt] = true;
                sz ++;
                nxt = loc[bs[nxt]];
            }
            cyc.push_back(sz-(sz&1));
        }
        sort(cyc.begin(),cyc.end());
        int curD = 1;
        int curU = n;
        bool dn = true;
        ll res = 0;
        for(int sz : cyc) {
            if(sz == 0) { continue;}
            // cout << "  " << sz << "\n";
            int st = curD;
            for(int i = 1; i < sz; i ++) {
                if(dn) {
                    res += curU - curD;
                    // cout << "   GO " << curD << " /-> " << curU << "\n";
                    curD ++;
                } else {
                    res += curU - curD;
                    // cout << "   GO " << curU << " \\-> " << curD << "\n";
                    curU --;
                }
                dn = !dn;
            }
            res += curU - st;
            curU --;
            dn = true;
        }
        cout << res << "\n";
    }
    return 0;
}