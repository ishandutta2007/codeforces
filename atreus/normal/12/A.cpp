#include <iostream>

using namespace std;

int main () {
    string a[3];
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    if (a[0][0] == a[2][2] && a[0][1] == a[2][1] && a[0][2] == a[2][0] && a[1][0] == a[1][2])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}