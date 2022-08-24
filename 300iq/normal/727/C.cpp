#include <bits/stdc++.h>

#define fc first
#define sc second
#define pb push_back
#define ll long long
#define ld long double

using namespace std;

map <pair <int, int>, bool> used;

int q(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int x;
    cin >> x;
    return x;
}

int main() {
    #ifdef ONPC
        //freopen("a.in", "r", stdin);
       // freopen("a.out", "w", stdout);
    #else
        //
        //
    #endif
    int n;
    cin >> n;
    vector <int> a(n + 1);
    ll d = q(1, 2), b = q(2, 3), c = q(1, 3);
    ll cur = (d + b + c) / 2;
    a[1] = cur - b;
    a[2] = cur - c;
    a[3] = cur - d;
    for (int i = 4; i <= n; i++) {
        a[i] = q(1, i) - a[1];
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}