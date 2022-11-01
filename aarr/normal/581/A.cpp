#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a;
    cin >> b;
    cout << min(a, b) << " " << (max(a, b) - min(a, b)) / 2 << endl;
}