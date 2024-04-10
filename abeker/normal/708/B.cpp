#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

const int MAX = 100000;

void bye() {
    puts("Impossible");
    exit(0);
}

int get(ll x) {
    for (int i = 1; i < MAX; i++)
        if ((ll)i * (i - 1) / 2 == x) return i;
    return -1;
}

void out(string s) {
    puts(s.c_str());
    exit(0);
}

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll tot = a + b + c + d;
    int len = get(tot);
    if (len == -1) bye();
    int zero = get(a);
    int one = get(d);
    if (zero == -1 || one == -1) bye();
    if (a == tot) out(string(zero, '0'));
    if (d == tot) out(string(one, '1'));
    if (one + zero != len) bye();
    if (c > (ll)zero * one) bye();
    string sol = "";
    if (c % one) sol = string(c % one, '1') + "0";
    sol += string(one - c % one, '1');
    sol += string(c / one, '0');
    sol = string(zero - count(sol.begin(), sol.end(), '0'), '0') + sol;
    out(sol);
    return 0;
}