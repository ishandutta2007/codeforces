#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const long double PI = acos(-1);

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    long double r, n;
    cin >> n >> r;
    long double arcs = 2 * r * sin(PI / n);
    long double area = arcs * arcs * (1 / tan(PI / n) - 1 / tan(1.5 * PI / n)) / 4;
    area = area * n;
    cout << setprecision(10) << fixed << area;
    return 0;
}