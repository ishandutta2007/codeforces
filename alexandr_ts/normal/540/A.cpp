#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

string a, b;

int main() {
    int n;
    cin >> n;
    cin >> a >> b;
    int s = 0;
    for (int i = 0; i < n; i++)
        s += min(abs(a[i] - b[i]), 10 - abs(a[i] - b[i]));
    cout << s;
}