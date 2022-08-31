#include <iostream>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    bool good = 0;
    while (n--) {
        cin >> x;
        good |= (x == 1);
    }
    cout << (good ? -1 : 1) << endl;
}