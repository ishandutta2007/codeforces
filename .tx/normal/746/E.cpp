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

int a[222222];
bool used[222222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    int lodd = 1;
    int leven = 2;
    int codd = 0;
    int ceven = 0;
    set<int> in_a;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        if (a[i] & 1) {
            codd++;
        } else {
            ceven++;
        }
        in_a.insert(a[i]);
    }

    int aa = 0;

    set<int> was;
    for (int i = 0; i < n; i++) {
        if (was.find(a[i]) != was.end()) {
            if (codd < ceven || (codd == ceven && a[i] % 2 == 1)) {
                while (in_a.find(lodd) != in_a.end()) {
                    lodd += 2;
                }
                if (lodd > m) {
                    cout << -1;
                    return 0;
                }
                aa++;
                bool wadd = a[i] % 2 == 1;
                a[i] = lodd;
                lodd += 2;
                if (!wadd) {
                    codd += 1;
                    ceven -= 1;
                }
            } else {
                while (in_a.find(leven) != in_a.end()) {
                    leven += 2;
                }
                if (leven > m) {
                    cout << -1;
                    return 0;
                }
                aa++;
                bool weven = a[i] % 2 == 0;
                a[i] = leven;
                leven += 2;
                if (!weven) {
                    codd -= 1;
                    ceven += 1;
                }
            }
        }

        was.insert(a[i]);
    }
    
//    if (n == 50000 && m == 40000) {
//        cout << codd << " " << ceven << endl;
//        cout << aa << endl;
//        cout << lodd << " " << leven << endl;
//    }

    for (int i = 0; codd < ceven && i < n; i++) {
        if (a[i] % 2 == 1) {
            continue;
        }
        while (was.find(lodd) != was.end()) {
            lodd += 2;
        }
        if (lodd > m) {
            cout << -1;
            return 0;
        }
        aa++;
        a[i] = lodd;
        lodd += 2;
        codd += 1;
        ceven -= 1;
    }

    for (int i = 0; codd > ceven && i < n; i++) {
        if (a[i] % 2 == 0) {
            continue;
        }
        while (was.find(leven) != was.end()) {
            leven += 2;
        }
        if (leven > m) {
            cout << -1;
            return 0;
        }
        aa++;
        a[i] = leven;
        leven += 2;
        codd -= 1;
        ceven += 1;
    }

    cout << aa << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}