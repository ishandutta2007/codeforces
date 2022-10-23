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
        long long n, k;
        cin >> n >> k;
        if (n <= 61) {
            long long total = 1LL << n - 1;
            if (k > total) {
                cout << -1 << '\n';
                continue;
            }
        }
        int put = 0;
        for (int i = 1; i <= n; ++i) {
            if (n - i - 1 <= 60 and 1LL << (n - i - 1) < k) {
                int j = i;
                while (j < n and 1LL << (n - j - 1) < k) {
                    k -= 1LL << (n - j - 1);
                    ++j;
                }
                for (int v = j; v >= i; v--) {
                    cout << v;
                    cout << " \n"[++put == n];
                }
                i = j;
            } else {
                cout << i;
                cout << " \n"[++put == n];
            }
        }
    }
    return 0;
}