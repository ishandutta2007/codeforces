#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    int pos = 0;
    for (auto it: t)
        if (s[pos] == it)
            ++ pos;

    cout << (pos + 1) << '\n';
    return 0;
}