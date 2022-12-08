#include <bits/stdc++.h>
#define pi pair<int,int>
#define ppi pair<pi,int>
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
        vector<ppi> as(n);
        vector<int> mx(n);
        int idx = 0;
        for(ppi &a : as) { cin >> a.f.f; a.s = idx++; }
        for(ppi &a : as) { cin >> a.f.s; }
        sort(as.begin(), as.end());
        int cur_mx = 0;
        for(int i = 0; i < n; i ++) {
            mx[i] = cur_mx;
            cur_mx = max(cur_mx,as[i].f.s);
        }
        int cur_mn = 1000000001;
        vector<bool> res(n);
        for(int i = n - 1; i >= 0; i --) {
            cur_mn = min(cur_mn,as[i].f.s);
            res[as[i].s] = true;
            if(mx[i] < cur_mn) {
                break;
            }
        }
        for(bool r : res) {
            cout << r;
        }
        cout << "\n";
    }
    return 0;
}