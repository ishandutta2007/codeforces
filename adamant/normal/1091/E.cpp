#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

const int mod = 998244353;

int fact(int n) {
    return n ? n * fact(n - 1) % mod : 1;
}

int get_type(vector<int> x, int m) {
    int sum_l = accumulate(all(x), 0LL);
    int sum_r = 0;
    int k = x.size();
    vector<int> wait;
    int out = 0;
    for(auto it: x) {
        sum_l -= it;
        k--;
        sum_r += it;
        wait.push_back(it);
        while(wait.size() && wait.back() >= k) {
            sum_r -= wait.back();
            out++;
            wait.pop_back();
        }
        int A = sum_l;
        int B = k * (k - 1) + sum_r + k * out;
        //cout << "!! " << A << ' ' << B << endl;
        if(A > B) {
            return it < m ? 2 : 0;
        }
    }
    return 1;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    int xr = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        xr ^= a[i] % 2;
    }
    sort(a, a + n);
    vector<int> d(a, a + n);
    int l = -1, r = n / 2;
    while(r - l > 1) {
        int m = (l + r) / 2 * 2 + xr;
        //cout << m << endl;
        auto it = d.insert(lower_bound(all(d), m), m);
        int c = get_type(d, m);
        d.erase(it);
        if(c == 0) {
            l = m / 2;
        } else {
            r = m / 2;
        }
    }
    //return 0;
    //cout << l << ' ' << r << endl;
    r = n;
    int L = l;
    while(r - l > 1) {
        int m = (l + r) / 2 * 2 + xr;
        auto it = d.insert(lower_bound(all(d), m), m);
        int c = get_type(d, m);
        d.erase(it);
        if(c == 2) {
            r = m / 2;
        } else {
            l = m / 2;
        }
    }
    int R = r;
    if(R - L == 1) {
        cout << -1 << endl;
    } else {
        for(int i = L + 1; i <= R - 1; i++) {
            cout << 2 * i + xr << ' ';
        }
    }
    return 0;
}