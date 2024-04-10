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

int rc() {
    int res = 0;
    while (getchar() == '|') {
        res++;
    }
    return res;
}

void pr(int x) {
    for (int i = 0; i < x; i++) {
        cout << "|";
    }
}

void ans(int a, int b, int c) {
    if (a > 0 && b > 0 && c > 0 && a + b == c) {
        pr(a);
        cout << "+";
        pr(b);
        cout << "=";
        pr(c);
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int a = rc();
    int b = rc();
    int c = rc();

    ans(a, b, c);
    ans(a - 1, b + 1, c);
    ans(a - 1, b, c + 1);
    ans(a + 1, b - 1, c);
    ans(a, b - 1, c + 1);
    ans(a + 1, b, c - 1);
    ans(a, b + 1, c - 1);

    cout << "Impossible";


    return 0;
}