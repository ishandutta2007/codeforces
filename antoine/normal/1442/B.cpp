#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = 998244353;
const int MxN = (int)2e5 + 9;
int a[MxN + 9];
int b[MxN + 9];

int f() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    map<int, int> b_inv;
    for(int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        b_inv[x] = i;
    }

    map<int, int> mp;
    vector<int> v(k, -1);
    for(int i = 0; i < n; ++i) {
        if(b_inv.count(a[i])) {
            mp[i] = 1;
            v[b_inv.at(a[i])] = i;
        } else
            mp[i]= -1;
    }

    for(int i : v)
        if(i == -1)
            return 0;

    ll ans = 1;
    for(int i : v) {
        auto it1 = mp.lower_bound(i);
        it1 = it1 == mp.begin() ? mp.end() : --it1;
        auto it2 = mp.lower_bound(i + 1);

        int cnt = (it1 != mp.end() && it1->second == -1) + (it2 != mp.end() && it2->second == -1);
        (ans *= cnt) %= mod;
        if(!ans)
            break;

        mp.erase(mp.find(i));
    }
    return ans;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int t;
    cin >> t;
    while(t--) {
        auto res = f();
        cout << res << '\n';
    }
    return 0;
}