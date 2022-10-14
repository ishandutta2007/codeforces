#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    char a[9][9];
    char b[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j += 3) {
            string s;
            cin >> s;
            a[i][j] = s[0];
            a[i][j + 1] = s[1];
            a[i][j + 2] = s[2];
            b[i][j] = s[0];
            b[i][j + 1] = s[1];
            b[i][j + 2] = s[2];

        }
    }
    int x, y;
    cin >> x >> y;
    x -= 1;
    y -= 1;
    int rx = x % 3;
    int ry = y % 3;
    bool flag = false;
    for ( int i = rx * 3; i < rx * 3 + 3; i++) {
        for ( int j = ry * 3; j < ry * 3 + 3; j++) {
            if (a[i][j] == '.') {
                a[i][j] = '!';
                flag = true;
            }
        }
    }
    if ( flag == true) {
        for ( int i = 0; i < 9; i++) {
            for ( int j = 0; j < 9; j++) {
                if ( j == 3 || j == 6) {
                    cout << " ";
                }
                cout << a[i][j];
            }
            if ( i == 2 || i == 5) {
            cout << endl;
            }
            cout << endl;
        }
    }
    else {
        for ( int i = 0; i < 9; i++) {
            for ( int j = 0; j < 9; j++) {
                if ( j == 3 || j == 6) {
                    cout << " ";
                }
                if (a[i][j] == '.') {
                    cout << "!";
                }
                else {
                cout << a[i][j];
                }
            }
            if ( i == 2 || i == 5) {
            cout << endl;
            }
            cout << endl;
        }
    }


    return 0;
}