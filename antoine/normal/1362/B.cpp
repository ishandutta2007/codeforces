#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;
typedef vector<int> vi;
typedef pair<int, int> pii;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        static int pres[1024], a[1024];
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            pres[a[i]] = 1;
        }

        int ans = 1;
        for(;; ++ans) {
            if(ans == 1024) {
                ans = -1;
                break;
            }
            bool ok = true;
            for(int i = 0; i < n; ++i)
                if(!pres[a[i]^ans]) {
                    ok = false;
                    break;
                }
            if(ok)
                break;
        }
        cout << ans << '\n';

        for(int i = 0; i < n; ++i)
            pres[a[i]] = 0;
    }

    return 0;
}