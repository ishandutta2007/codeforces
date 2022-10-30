#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    long long t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long s, a, b, c;
        cin >> s >> a >> b >> c;
        cout << s / c + b * (s / (a * c)) << "\n";
    }
    return 0;
}