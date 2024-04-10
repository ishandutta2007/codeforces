#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sir;
    cin >> sir;

    for (int i = -1; i < static_cast <int>(sir.size()); i++)
        for (int j = i + 1; j <= sir.size(); j++)
            if (sir.substr(0, i + 1) + sir.substr(j, sir.size() - j) == "CODEFORCES") {
                cout << "YES\n";
                return 0;
            }

    cout << "NO\n";
    return 0;
}