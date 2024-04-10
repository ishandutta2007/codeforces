#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char c[2][2][2];
string s[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                cin >> c[i][j][k];
    for(int i = 0; i < 2; i++) {
        if(c[i][0][0] != 'X')
            s[i] += c[i][0][0];
        if(c[i][0][1] != 'X')
            s[i] += c[i][0][1];
        if(c[i][1][1] != 'X')
            s[i] += c[i][1][1];
        if(c[i][1][0] != 'X')
            s[i] += c[i][1][0];
    }
    for(int i = 0; i < 3; i++) {
        if(s[0] == s[1]) {
            cout << "YES\n";
            return 0;
        }
        rotate(s[0].begin(), s[0].begin() + 1, s[0].end());
    }
    cout << "NO\n";
    return 0;
}