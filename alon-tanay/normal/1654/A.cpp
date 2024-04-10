#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define pi pair<int,int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int mx = 0;
        int sx = 0;
        for(int i = 0; i < n; i ++) {
            int x;
            cin >> x;
            if(x >= mx) {
                sx = mx;
                mx = x;
            } else if(x > sx) {
                sx = x;
            }
        }
        cout << sx + mx << "\n";
    }
    return 0;
}