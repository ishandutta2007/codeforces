#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;

int main() {
    int a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    int lft = max(0, a - x) / 2 + max(0, b - y) / 2 + max(0, c - z) / 2;
    int need = max(0, x - a) + max(0, y - b) + max(0, z - c);
    if (need <= lft)
        cout << "Yes";
    else
        cout << "No";
}