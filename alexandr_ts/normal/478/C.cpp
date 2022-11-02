#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int N = 1e4;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a < c)
        swap(a, c);
    if (a < b)
        swap(a, b);
    if (a > 2 * (b + c))
        cout << b + c;
    else
        cout << (a + b + c) / 3;
}