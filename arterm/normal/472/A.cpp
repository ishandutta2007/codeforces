#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define M 1000100



int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    int n;

    cin >> n;

    if (n % 2 == 0) {
        cout << 4 << " " << n - 4 << "\n";
    }
    else {
        cout << 9 << " " << n - 9 << "\n";
    }
    
    return 0;
}