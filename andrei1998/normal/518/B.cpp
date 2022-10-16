#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char inv (char x) {
    if (islower(x))
        return toupper(x);
    return tolower(x);
}

int frecv[1005];

int main()
{
    ios_base::sync_with_stdio(false);

    string s, t;

    cin >> s >> t;

    for (int i = 0; i < t.size(); i++)
        frecv[t[i]] ++;

    int a = 0, b = 0;
    for (int i = 0; i < s.size(); i++) {
        if (frecv[s[i]]) {
            a++;
            frecv[s[i]]--;

            s[i] = '0';
        }
    }

    for (int i = 0; i < s.size(); i++)
        if (s[i] != '0')
            if (frecv[inv(s[i])]) {
                b++;
                frecv[inv(s[i])] --;
            }

    cout << a << ' ' << b << endl;
    return 0;
}