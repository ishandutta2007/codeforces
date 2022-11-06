#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T>
using heap = priority_queue<T, vector<T>, std::greater<T>>;

typedef long long lint;

int c[33];
int n;
string s;

int M = 1e9 + 7;

int d[1111];

int cc[33];

int a1() {
    d[0] = 1;
    for (int i = 0; i < n; i++) {
        d[i + 1] = d[i];
        int mlen = c[s[i]];
        for (int j = 2; j <= i + 1; j++) {
            mlen = min(mlen, c[s[i - j + 1]]);
            if (j > mlen) {
                break;
            }
            d[i + 1] = (d[i + 1] + d[i - j + 1]) % M;
        }
    }
    return d[n];
}

int a2() {
    int res = 1;
    for (int i = 0; i < n; i++) {
        int mlen = c[s[i]];
        for (int j = i + 1; j < n; j++) {
            mlen = min(mlen, c[s[j]]);
            if (j - i + 1 <= mlen) {
                res = max(res, j - i + 1);
            } else {
                break;
            }
        }
    }
    return res;
}

int a3() {
    memset(cc, 0, sizeof(cc));
    int res = 1;
    int mlen = c[s[0]];
    int l = 0;
    for (int i = 1; i < n; i++) {
        mlen = min(mlen, c[s[i]]);
        if (i - l + 1 > mlen) {
            l = i;
            res++;
            mlen = c[s[i]];
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    sci(n, s);
    for (int i = 0; i < n; i++) {
        s[i] -= 'a';
    }
    for (int i = 0; i < 26; i++) {
        sci(c[i]);
    }
    
    cout << a1() << "\n" << a2() << "\n" << a3();

    return 0;
}