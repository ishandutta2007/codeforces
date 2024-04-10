#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int ans = 0;
    char pos = 'a';
    for (auto ch: str) {
        ans += min(abs(ch - pos), 26 - abs(ch - pos));
        pos = ch;
    }

    cout << ans << '\n';
    return 0;
}