#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--) {
        int64_t p, q;
        cin >> p >> q;
        if (p % q) {
            cout << p << '\n';
            continue;
        }
        vector<int> p_q;
        int qq = q;
        for (int i = 2; i * i <= q; i++) {
            if (q % i == 0) {
                p_q.push_back(i);
                while (q % i == 0) q /= i;
            }
        }
        if (q != 1) p_q.push_back(q);
        int res = 1;
        for (int e : p_q) {
            int foo = p;
            while (foo % qq == 0) foo /= e;
            res = max(res, foo);
        } 
        cout << res << '\n';
    }

    return 0;
}