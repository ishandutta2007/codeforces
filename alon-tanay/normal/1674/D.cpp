#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define vi vector<int>
#define INF 1073741823

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
        for(int i = 0; i < n; i ++) {
            cin >> as[i];
        }
        int cur = 1e9;
        bool fail = false;
        for(int i = n - 1; i >= 1; i -= 2) {
            if(max(as[i],as[i-1]) > cur) {
                fail = true;
                break;
            }
            cur = min(as[i],as[i-1]);
        }
        if(n&1) {
            if(as[0] > cur) {
                fail = true;
            }
        }
        cout << (fail ? "NO\n" : "YES\n");
    }
    return 0;
}