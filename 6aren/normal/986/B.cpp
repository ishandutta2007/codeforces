#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

struct BIT {
    vector<int> bit;
    int maxn;
    
    BIT(int n) {
        bit.resize(n + 2, 0);
        maxn = n + 1;
    }

    void update(int k, int val) {
        for (int i = k; i < maxn; i += (i & (-i))) {
            bit[i] += val;
        }
    }

    int get(int k) {
        int res = 0;
        for (int i = k; i > 0; i -= (i & (-i))) {
            res += bit[i];
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    BIT bit = BIT(n + 5);
    long long ans = 0;
    for (int i = n; i >= 1; i--) {
        ans += bit.get(a[i]);
        bit.update(a[i], 1);
    }
    if (ans % 2 == (3 * n) % 2) cout << "Petr";
    else cout << "Um_nik";
    return 0;
}