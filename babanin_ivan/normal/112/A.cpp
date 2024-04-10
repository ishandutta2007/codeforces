#include <iostream>
#include <string>
using namespace std;

string s1, s2;
bool b = false;

void main () {
    /*freopen ("input.txt", "rt", stdin);
    freopen ("output.txt", "wt", stdout);*/

    cin >> s1 >> s2;

    for (int i = 0; i < s1.length(); i++) {
        if (tolower(s1[i]) > tolower(s2[i])) {
            cout << "1"; b = true; break;
        }
        else if (tolower(s1[i]) < tolower(s2[i])) {
            cout << "-1"; b = true;  break;
        }
    }
    if (!b) cout << "0";
}