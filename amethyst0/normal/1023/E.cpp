#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#define ll long long

using namespace std;

const int maxn = 510;

vector <char> a, b;

bool can(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    string ans;
    
    cin >> ans;
    
    if (ans == "YES") {
        return 1;
    }
    
    return 0;
}

int main() {
    int n;
    
    cin >> n;
    
    int x = 1, y = 1;
    
    for (int i = 0; i < n - 1; i++) {
        if (can(x, y + 1, n, n)) {
            y += 1;
            a.push_back('R');
        } else {
            x += 1;
            a.push_back('D');
        }
    }

    x = n, y = n;
    
    for (int i = 0; i < n - 1; i++) {
        if (can(1, 1, x - 1, y)) {
            x -= 1;
            b.push_back('D');
        } else {
            y -= 1;
            b.push_back('R');
        }
    }
    
    cout << "! ";
    
    for (int i = 0; i < (int)a.size(); i++) {
        cout << a[i];
    }
    
    for (int i = (int)b.size() - 1; i >= 0; i--) {
        cout << b[i];
    }
    
    cout << endl;
    
    return 0;
}