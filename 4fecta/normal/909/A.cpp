#include <bits/stdc++.h>
using namespace std;
string x, y;
int main() {
    cin >> x >> y;
    x += "z";
    for (int i = 1; i < x.length(); i++) {
        if (y[0] <= x[i]) {
            for (int j = 0; j < i; j++) printf("%c", x[j]);
            printf("%c\n", y[0]);
            return 0;
        }
    }
}