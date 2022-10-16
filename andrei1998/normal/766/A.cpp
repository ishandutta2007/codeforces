#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    if (a == b) {
        cout << "-1\n";
        return 0;
    }

    cout << max(a.size(), b.size()) << '\n';
    return 0;
}