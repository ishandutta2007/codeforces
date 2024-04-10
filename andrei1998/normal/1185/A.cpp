#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector <int> v = {a, b, c};
    sort(v.begin(), v.end());
    a = v[0];
    b = v[1];
    c = v[2];
    cout << max(0, d - b + a) +
            max(0, d - c + b) << endl;
    return 0;
}