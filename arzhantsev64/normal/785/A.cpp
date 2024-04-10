#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s == "Tetrahedron") {
            ans += 4;
        }
        if (s == "Cube") {
            ans += 6;
        }
        if (s == "Octahedron") {
            ans += 8;
        }
        if (s == "Dodecahedron") {
            ans += 12;
        }
        if (s == "Icosahedron") {
            ans += 20;
        }
    }
    cout << ans;
}