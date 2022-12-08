#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define vi vector<int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> cs(n+1);
        for(int i = 0; i < n - 1; i ++) {
            int p;
            cin >> p;
            cs[p-1] ++;
        }
        cs[n] = 1;
        sort(cs.begin(), cs.end());
        int sz = n + 1;
        for(int i = 0; i <= n; i ++) {
            if(cs[i]) {
                break;
            }
            sz --;
        }
        int res = sz;
        int s = 0;
        priority_queue<int> pq;
        for(int i = n; i >= 0; i --) {
            if(cs[i] == 0) { break; }
            pq.push(cs[i] - sz + s);
            s ++;
        }
        // cout << " ? " << res << "\n";
        int timer = 0;
        while(pq.size()) {
            int tp = pq.top();
            // cout << "  " << tp << "\n";
            if(tp-timer <= 0) { break; }
            res ++;
            timer ++;
            pq.pop();
            pq.push(tp-1);
        }
        cout << res << "\n";
    }
    return 0;
}