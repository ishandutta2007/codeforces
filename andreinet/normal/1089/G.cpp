#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    
    while(t--) {
        vector<int> v(7, 0);
        
        int k; cin >> k;

        for(int i = 0; i < 7; i += 1) {
            cin >> v[i];
        }

        vector<int> pref(7, 0), suf(7, 0);
        
        for(int i = 0; i < 7; i += 1) {
            int prev = (i == 0 ? 0 : pref[i - 1]);
            pref[i] = prev + v[i];
        }

        for(int i = 7 - 1; i >= 0; i -= 1) {
            int prev = (i == 6 ? 0 : suf[i + 1]);
            suf[i] = prev + v[i];
        }
        
        int ans = 1e9;

        for(int i = 0; i < 7; i += 1) {
            if(pref[i] == k)
                ans = min(ans, i + 1);
            for(int j = 0; j < 7; j += 1) {
                int rem = (k - (suf[j] + pref[i]));

                if(rem >= 0) {;
                    if(rem % pref[6] == 0) {
                        ans = min(ans, i + 1 + 7 - j + (rem / pref[6]) * 7);
                    }
                }

                if(j > i and pref[j] - pref[i] == k) {
                    ans = min(ans, j - i);
                }
            }
        }

        cout << ans << "\n";
    }
}