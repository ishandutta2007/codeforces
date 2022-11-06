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

typedef long long lint;

int k, x, n, m;

void get_st(int m, char f, char e, int& mn, int& mx) {
    if (m == 2) {
        if (f == 'A' && e == 'C') {
            mn = mx = 1;
        } else {
            mn = mx = 0;
        }
        return;
    }
    
    if (f != 'A') {
        m--;
    }
    if (e != 'C') {
        m--;
    }
    mn = 0;
    mx = m / 2;
}

string build(int n, int x, char f, char e) {
    string s;
    s += f;
    if (n == 1) {
        return s;
    }
    while (s.size() + 1 < n) {
        if (x > 0) {
            if (s.back() == 'A') {
                s += 'C';
                x--;
            } else {
                s += 'A';
            }
        } else {
            s += 'B';
        }
    }
    
    s += e;
    return s;
}

bool ok(int x1, char f1, char e1, int x2, char f2, char e2) {
    for (int i = 2; i < k; i++) {
        int nx = x1 + x2;
        if (e1 == 'A' && f2 == 'C') {
            nx++;
        }
        char nf = f1;
        char ne = e2;
        x1 = x2;
        f1 = f2;
        e1 = e2;
        x2 = nx;
        f2 = nf;
        e2 = ne;
        
        if (x2 > x) {
            break;
        }
    }

    return x2 == x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    sci(k, x, n, m);
    
    for (char f1 = 'A'; f1 <= 'C'; f1++) {
        for (char e1 = 'A'; e1 <= 'C'; e1++) {
            if (n == 1 && f1 != e1) {
                continue;
            }
            for (char f2 = 'A'; f2 <= 'C'; f2++) {
                for (char e2 = 'A'; e2 <= 'C'; e2++) {
                    if (m == 1 && f2 != e2) {
                        continue;
                    }
                    
                    int mn1, mx1, mn2, mx2;
                    
                    get_st(n, f1, e1, mn1, mx1);
                    get_st(m, f2, e2, mn2, mx2);
                    
                    for (int i1 = mn1; i1 <= mx1; i1++) {
                        for (int i2 = mn2; i2 <= mx2; i2++) {
                            if (ok(i1, f1, e1, i2, f2, e2)) {
                                string s = build(n, i1, f1, e1);
                                string t = build(m, i2, f2, e2);
                                cout << s << "\n" << t;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << "Happy new year!";

    return 0;
}