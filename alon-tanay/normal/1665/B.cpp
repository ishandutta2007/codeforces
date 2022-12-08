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
        map<int,int> cnt;
        for(int i = 0; i < n; i ++) {
            int x;
            cin >> x;
            cnt[x] ++;
        }
        int mx = 0;
        for(pi c : cnt) {
            mx = max(mx,c.second);
        }
        int k = mx;
        int res = 0;
        while(k < n) {
            res ++;
            int newk = min(n,k * 2);
            res += newk - k;
            k = newk;
        }
        cout << res << "\n";
    }
    return 0;
}