#include <bits/stdc++.h>

using namespace std;

int val(char c) {
    if (c == 'Q') return 9;
    if (c == 'R') return 5;
    if (c == 'B' || c == 'N') return 3;
    if (c == 'P') return 1;
    return 0;
}

int main() {
    int w = 0, b = 0;
    char c;
    for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
        cin >> c;
        if (c == '.')
            continue;
        if (islower(c)) {
            c += 'A' - 'a';
            b += val(c);
        }
        else
            w += val(c);
    }
    if (w > b)
        cout << "White";
    else if (b > w)
    cout << "Black";
    else
        cout << "Draw";

}