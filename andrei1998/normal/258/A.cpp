#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    bool deleted = false;
    for (int i = 0; i < str.size(); ++ i)
        if (!deleted && (str[i] == '0' || i + 1 == str.size()))
            deleted = true;
        else
            cout << str[i];
    cout << '\n';

    return 0;
}