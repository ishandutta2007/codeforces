#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = (int)s.size();
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U')
            y++;
        if (s[i] == 'D')
            y--;
        if (s[i] == 'R')
            x++;
        if (s[i] == 'L')
            x--;
    }
    int cx = 0, cy = 0;
    for (int i = 0; i < n; i++) {
        if (x != 0 && y != 0) {
            if ((a - cx) % x == 0 && (b - cy) % y == 0 &&
                (a - cx) / x == (b - cy) / y && (a - cx) / x >= 0) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        if (x != 0 && y == 0) {
            if ((a - cx) % x == 0 && b - cy == 0 && (a - cx) / x >= 0){
                cout << "Yes" << endl;
                return 0;
            }
        }
        if (x == 0 && y != 0) {
            if (a - cx == 0 && (b - cy) % y == 0 && (b - cy) / y >= 0) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        if (x == 0 && y == 0) {
            if (a == cx && b == cy) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        if (s[i] == 'U')
            cy++;
        if (s[i] == 'D')
            cy--;
        if (s[i] == 'R')
            cx++;
        if (s[i] == 'L')
            cx--;
    }
    cout << "No" << endl;
    return 0;
    return 0;
}