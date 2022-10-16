#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a[4];
    for (int i = 0; i < 4; ++ i)
        cin >> a[i];

    string str;
    cin >> str;

    int ans = 0;
    for (auto it: str)
        ans += a[it - '1'];

    cout << ans << '\n';
    return 0;
}