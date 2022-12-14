#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1){
        cout << n << " " << 1 << endl;
        cout << 1 << endl;
        return 0;
    }
    cout << 2 * n - 2 << " " << 2 << endl;
    cout << 1 << " " << 2 << endl;
    return 0;
}