#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int num_op = 0;
    cin >> num_op;

    multiset<int> ms1, ms2;
    int k1 = 0, k2 = 0;
    ll sum1 = 0, sum2 = 0;
    map<int, int> mp;

    while(num_op--) {
        int tp, x;
        cin >> tp >> x;
        if(x < 0) {
            x=  -x;
            if(ms1.count(x)) {
                ms1.erase(x);
                k1 -= mp.at(x);
                sum1 -= x;
            } else {
                ms2.erase(ms2.find(x));
                k2 -= mp.at(x);
                sum2 -= x;
            }
            mp.erase(x);
        } else {
            mp[x] = tp;

            if (ms2.empty() || (!ms1.empty() && x <= *ms1.rbegin())) {
                ms1.insert(x);
                k1 += tp;
                sum1 += x;
            } else {
                ms2.insert(x);
                k2 += tp;
                sum2 += x;
            }
        }

        const int n = (int)ms1.size() + (int)ms2.size();
        const int k = k1 + k2;
        const ll sum = sum1 + sum2;

        while(ms1.size() > n - k) {
            int y = *--ms1.end();
            ms1.erase(y);
            k1 -= mp[y];
            sum1 -= y;

            ms2.insert(y);
            k2 += mp[y];
            sum2 += y;
        }

        while(ms2.size() > k) {
            int y = *ms2.begin();
            ms2.erase(y);
            k2 -= mp[y];
            sum2 -= y;

            ms1.insert(y);
            k1 += mp[y];
            sum1 += y;
        }

        if(k == 0)
            cout << sum << '\n';
        else if(k == n)
            cout << sum + sum - *ms2.begin() << '\n';
        else if(k == k2)
            cout << sum + sum2 - *ms2.begin() + *ms1.rbegin() << '\n';
        else
            cout << sum + sum2 << '\n';

    }
    return 0;
}