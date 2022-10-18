#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;
const int mod = 998244353;

int mul(int a, int b) {
    return (a * b) % mod;
}
int add(int a, int b) {
    return (a + b) % mod;
}

void solve() {
    int N = 52;
    int fib[N];
    int sum[N];
    fib[0] = fib[1] = 1;
    sum[0] = 1, sum[1] = 2;
    for(int i = 2; i < N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        sum[i] = sum[i - 1] + fib[i];
    }
    int n;
    cin >> n;
    int c[n];
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    if(n == 1) {
        if(c[0] == 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        return;
    }
    int sm = accumulate(c, c + n, 0LL);
    int s_idx = 0;
    while(s_idx < N) {
        if(sum[s_idx++] == sm) {
            break;
        }
    }
    s_idx--;
    if(sum[s_idx] != sm) {
        cout << "No\n";
        return;
    }
    auto to_fib = [&](int x) {
        int ans = 0;
        for(int i = N - 1; i >= 0; i--) {
            if(x >= fib[i]) {
                x -= fib[i];
                ans ^= 1LL << i;
            }
        }
        return ans;
    };
    int test = 0;
    int tfb[n][2];
    for(int i = 0; i < n; i++) {
        tfb[i][0] = to_fib(c[i]);
        tfb[i][1] = to_fib(c[i] - 1);
        //cerr << bitset<6>(tfb[i][0]) << ' ' << bitset<6>(tfb[i][1]) << "\n";
        test ^= tfb[i][0];
    }
    int check = (1LL << (s_idx + 1)) - 4;
    for(int i = 0; i < n; i++) {
        int A = tfb[i][0] ^ tfb[i][1];
        test ^= A;
        for(int j = 0; j < i; j++) {
            int B = tfb[j][0] ^ tfb[j][1];
            
            test ^= B;
            //cout << bitset<6>(test) << ' ' << test << ' ' << check << endl;
            if(test == check) {
                cout << "Yes\n";
                return;
            }
            test ^= B;
        }
        test ^= A;
    }
    cout << "No\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}