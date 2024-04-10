#include <iostream>

using namespace std;

const int H = 60, D = 24 * H;

int main() {
    ios_base::sync_with_stdio(false);
    int h, m;
    char ch;
    cin >> h >> ch >> m;
    int a = h * H + m;
    cin >> h >> ch >> m;
    int b = h * H + m, c = (((a - b) % D) + D) % D;
    cout << (c / H < 10? "0" : "") << c / H << ':'
         << (c % H < 10? "0" : "") << c % H << '\n';
    return 0;
}