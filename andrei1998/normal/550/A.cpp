#include <iostream>
#include <string>

using namespace std;

string str, aux;

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> str;

    if (str.find("AB") != string :: npos) {
        aux = str.substr(str.find("AB") + 2, str.size() - str.find("AB") - 2);

        if (aux.find("BA") != string :: npos) {
            cout << "YES\n";
            return 0;
        }
    }

    if (str.find("BA") != string :: npos) {
        aux = str.substr(str.find("BA") + 2, str.size() - str.find("BA") - 2);

        if (aux.find("AB") != string :: npos) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}