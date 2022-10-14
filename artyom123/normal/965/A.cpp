#include <bits/stdc++.h>

using namespace std;


int main () {
    int k, n, s, p;
    cin >> k >> n >> s >> p;
    int need = (n + s - 1) / s;
    need *= k;
    cout << (need + p - 1) / p;
    return 0;
}