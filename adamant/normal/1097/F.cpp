#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)

const int maxn = 7001;

bitset<maxn> to_and[maxn], to_xor[maxn];
bitset<maxn> sets[100000];

int square_free(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % (i * i) == 0) {
            return false;
        }
    }
    return true;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < maxn; i++) {
        for(int j = 1; j < maxn; j++) {
            if(i % j == 0) {
                to_xor[i][j] = 1;
                to_and[j][i] = square_free(i / j);
            }
        }
    }
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int x, v;
            cin >> x >> v;
            sets[x - 1] = to_xor[v];
        } else if(t == 2) {
            int x, y, z;
            cin >> x >> y >> z;
            sets[x - 1] = sets[y - 1] ^ sets[z - 1];
        } else if(t == 3) {
            int x, y, z;
            cin >> x >> y >> z;
            sets[x - 1] = sets[y - 1] & sets[z - 1];
        } else {
            int x, v;
            cin >> x >> v;
            cout << (sets[x - 1] & to_and[v]).count() % 2;
        }
    }
    return 0;
}