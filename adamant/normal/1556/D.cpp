#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int int64_t
#define all(x) begin(x), end(x)

int mod = 998244353;

int add(int a, int b) {
    return (a + b) % mod;
}
int sub(int a, int b) {
    return (a + mod - b) % mod;
}
int mul(int a, int b) {
    return a * b % mod;
}
int bpow(int x, int n) {
    return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}
int inv(int x) {
    return bpow(x, mod - 2);
}

const int maxn = 6e5 + 42;

int OR(int x, int y) {
    cout << "or " << x + 1 << ' ' << y + 1 << endl;
    int r;
    cin >> r;
    return r;
}

int AND(int x, int y) {
    cout << "and " << x + 1 << ' ' << y + 1 << endl;
    int r;
    cin >> r;
    return r;
}

int FIN(int r) {
    cout << "finish " << r << endl;
    exit(0);
}

const int K = 30;

typedef bitset<K> bits;

void solve() {
    int n, k;
    cin >> n >> k;
    bits orr[n], ann[n], a[n];
    for(int i = 1; i < n; i++) {
        orr[i] = OR(0, i);
        ann[i] = AND(0, i);
    }
    bits an12 = AND(1, 2);
    for(int z = 0; z < K; z++) {
        if(ann[1][z] || ann[2][z]) {
            a[0][z] = 1;
        } else if(orr[1][z] && orr[2][z] && !an12[z]) {
            a[0][z] = 1;
        } else {
            a[0][z] = 0;
        }
    }
    for(int i = 1; i < n; i++) {
        for(int z = 0; z < K; z++) {
            if(a[0][z]) {
                a[i][z] = ann[i][z];
            } else {
                a[i][z] = orr[i][z];
            }
        }
    }
    sort(a, a + n, [&](bits x, bits y){return x.to_ulong() < y.to_ulong();});
    FIN(a[k - 1].to_ulong());
}

signed main() {
    //ignore = freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}