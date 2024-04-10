#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    for (int i = s.size() - 1; i >= 0; i--)
        if (s[i] == 'z')
            s[i] = 'a';
        else {
            s[i] ++;
            break;
        }

    if (s == t) {
        cout << "No such string\n";
        return 0;
    }

    cout << s << '\n';
    return 0;
}