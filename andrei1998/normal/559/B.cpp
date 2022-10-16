#include <iostream>
#include <string>

using namespace std;

//Clase de echivalenta
void repr(string &s) {
    if (s.size() & 1)
        return ;

    string s1 = s.substr(0, s.size() / 2);
    repr(s1);

    string s2 = s.substr(s.size() / 2, s.size());
    repr(s2);

    if (s1 < s2)
        s = s1 + s2;
    else
        s = s2 + s1;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    repr(s1);
    repr(s2);

    if (s1 == s2)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}