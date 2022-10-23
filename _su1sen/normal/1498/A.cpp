#include <bits/stdc++.h>

using namespace std;

using int128 = __int128_t;

#define rep(i, n)         for (int i = 0; i < n; ++i)
#define reps(i, n, s)     for (int i = 0; i < n; i += s)
#define repl(i, l, r)     for (int i = l; i < r; ++i)
#define repsl(i, l, r, s) for (int i = l; i < r; i += s)

#define all(iterable) iterable.begin(), iterable.end()

template <typename T>
void print_vector(vector<T>& vec, string sep = " ", string end = "\n") {
    int n = vec.size();
    rep(i, n) {
        cout << vec[i];
        if (i < n - 1) cout << sep;
        else cout << end;
    }
}

int main() {
    int t;
    cin >> t;
    while (t --> 0) {
        long long n;
        cin >> n;
        while (true) {
            long long digit_sum = 0;
            long long m = n;
            while (m) {
                digit_sum += m % 10;
                m /= 10;
            }
            long long g = __gcd(digit_sum, n);
            if (g > 1) {
                cout << n << '\n';
                break;
            }
            ++n;
        }
    }
    return 0;
}