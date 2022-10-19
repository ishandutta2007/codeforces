#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
#ifdef TURTLE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    char up = a.front();
    char down = a.back();
    char left = b.front();
    char right = b.back();

    string sum;
    sum.push_back(up);
    sum.push_back(right);
    sum.push_back(down);
    sum.push_back(left);

    if (sum == ">v<^" || sum == "<^>v")
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}