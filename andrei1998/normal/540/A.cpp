#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += min(abs(a[i] - b[i]), 10 - abs(a[i] - b[i]));

    cout << ans << '\n';
    return 0;
}