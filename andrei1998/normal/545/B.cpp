#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    int n = s.size();

    string p;
    int a = 0, b = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            p += s[i];
        }
        else if (a < b) {
            p += s[i];
            a ++;
        }
        else {
            p += t[i];
            b ++;
        }
    }

    if (a == b)
        cout << p << '\n';
    else
        cout << "impossible" << endl;

    return 0;
}