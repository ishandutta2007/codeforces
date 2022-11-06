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
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int pr[555555];

int cn[555555];
int a[222222];
bool here[222222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    memset(pr, -1, sizeof(pr));
    for (int i = 2; i < 555555; i++) {
        if (pr[i] == -1) {
            for (int j = i + i; j < 555555; j += i) {
                if (pr[j] == -1) {
                    pr[j] = i;
                }
            }
        }
    }

    scid(n, q);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }

    int call = 0;
    int cone = 0;
    lint cans = 0;


    while (q-- > 0) {
        scid(x);
        --x;
        vector<int> ps;
        int c = a[x];
        while (pr[c] != -1) {
            if (ps.empty() || pr[c] != ps.back()) {
                ps.push_back(pr[c]);
            }
            c /= pr[c];
        }
        if (c != 1 && (ps.empty() || c != ps.back())) {
            ps.push_back(c);
        }
        int m = ps.size();

        if (!here[x]) {
            if (a[x] == 1) {
                cone++;
            } else {
                cans += call;
                call++;
                for (int i = 1; i < (1 << m); i++) {
                    int t = 1;
                    for (int j = 0; j < m; j++) {
                        if ((i >> j) & 1) {
                            t *= ps[j];
                        }
                    }
                    if (__builtin_popcount(i) & 1) {
                        cans -= cn[t];
                    } else {
                        cans += cn[t];
                    }
                    cn[t]++;
                }
            }
        } else {
            if (a[x] == 1) {
                cone--;
            } else {
                call--;
                cans -= call;
                for (int i = 1; i < (1 << m); i++) {
                    int t = 1;
                    for (int j = 0; j < m; j++) {
                        if ((i >> j) & 1) {
                            t *= ps[j];
                        }
                    }
                    cn[t]--;
                    if (__builtin_popcount(i) & 1) {
                        cans += cn[t];
                    } else {
                        cans -= cn[t];
                    }
                }
            }
        }
        here[x] ^= true;
        cout << cans + 1LL * cone * call + 1LL * cone * (cone - 1) / 2 << "\n";
    }



    return 0;
}