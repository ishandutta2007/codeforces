#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

#define all(x) begin(x), end(x)

template<class Iter, class Value>
struct StreamRange {
    Iter it; uint n;
    StreamRange(Iter it, uint n) : it(it), n(n) {}
    friend ostream& operator<<(ostream& os, StreamRange const& r) {
        copy_n(r.it, r.n, ostream_iterator<Value>(os, " ")); return os;
    }
    friend istream& operator>>(istream& is, StreamRange const& r) {
        copy_n(istream_iterator<Value>(is), r.n, r.it); return is;
    }
};
template<class Value, class Iter>
StreamRange<Iter, Value> range(Iter it, uint n) {
    return StreamRange<Iter, Value>(it, n);
}

void assume(int expr) {
    if (!expr) __builtin_unreachable();
}

constexpr uint N = 2e5 + 10;

uint n, A[N], B[N];
ull Sl, Sr;
string s;

void apply(uint x, char c) {
    cout << x << ' ' << c << '\n';
    (c == 'L' ? Sl : Sr) += x;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> range<uint>(A, n) >> s;
    sort(A, A+n);
    uint p = n;
    for (uint i = n; i --> 0;) {
        if (i == 0 || s[i-1] != s[i]) {
            B[i] = A[--p];
        }
    }
    for (uint i = 0; i < n; i++) {
        if (B[i]) {
            apply(B[i], s[i]);
        } else {
            uint x = A[--p];
            if (s[i] == 'L') {
                if (Sr + x < Sl) apply(x, 'R');
                else apply(x, 'L');
            } else {
                if (Sl + x < Sr) apply(x, 'L');
                else apply(x, 'R');
            }
        }
    }
    return 0;
}