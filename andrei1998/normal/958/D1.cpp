#include <bits/stdc++.h>

using namespace std;

struct Frac {
    int a, b;
    Frac(): a(0), b(1) {}
    Frac(int _a, int _b): a(_a), b(_b) {}
    friend bool operator<(const Frac &a, const Frac &b) {
        return 1LL * b.b * a.a < 1LL * b.a * a.b;
    }
};

map <Frac, int> Mp;

const int NMAX = 2000000 + 5;
Frac fr[NMAX];

int main() {
    ios_base :: sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++ i) {
        char ch;
        int a, b, c;
        cin >> ch >> a >> ch >> b >> ch >> ch >> c;
        fr[i] = Frac(a + b, c);
        Mp[fr[i]] ++;
    }
    for (int i = 1; i <= N; ++ i)
        cout << Mp[fr[i]] << " \n"[i == N];
    return 0;
}