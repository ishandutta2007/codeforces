#include <bits/stdc++.h>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2){
        int k = y2 - y1;
        if (k < 0)
            k = -k;
        k ++;
        cout << 2 * k + 4;
    }
    else if (y1 == y2){
        int k = x2 - x1;
        if (k < 0)
            k = -k;
        k ++;
        cout << 2 * k + 4;
    }
    else {
        int k = x2 - x1;
        int l = y2 - y1;
        if (k < 0)
            k = -k;
        if (l < 0)
            l = -l;
        l ++;
        k ++;
        cout << 2 * l + 2 * k;
    }
    return 0;
}