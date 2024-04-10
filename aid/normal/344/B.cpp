#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    int minab = min(a, b);
    for(int i = 0; i <= minab; i++)
        if(b - i == c - a + i) {
            cout << i << ' ' << b - i << ' ' << a - i << '\n';
            return 0;
        }
    cout << "Impossible\n";
}