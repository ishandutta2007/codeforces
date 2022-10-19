#include <iostream>
using namespace std;

typedef long long ll;

const int MOD = 1000003;

ll N, K;

void load() {
    cin >> N >> K;
}

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    else if (x < 0) x += MOD;
    return x;
}

inline int mul(int x, int y) {
    return (ll)x * y % MOD;
}

int pot(int x, ll y) {
    int res = 1;
    for (; y; y /= 2) {
        if (y % 2) res = mul(res, x);
        x = mul(x, x);
    }
    return res;
}

int inv(int x) {
    return pot(x, MOD - 2);
}

void solve() {
    int exp = 0;
    for (ll x = 1; x < K; x *= 2)
        exp++;
        
    if (exp > N) {
        cout << "1 1" << endl;
        return;
    }
    
    int tot = pot(2, N);
    tot = pot(tot, K);
    
    ll v2 = N;
    for (ll x = (K - 1) / 2; x; x /= 2) 
        v2 += x;
    
    tot = mul(tot, inv(pot(2, v2)));
        
    if (K >= MOD) {
        cout << tot << " " << tot << endl;
        return;
    }
    
    int sol = inv(pot(2, v2));
    int two = pot(2, N);
    for (int i = 0; i < K; i++)
        sol = mul(sol, add(two, -i));
        
    cout << add(tot, -sol) << " " << tot << endl;
}

int main() {
    load();
    solve();
    return 0;
}