#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 20; i >= 0; i--)
        if(n & (1 << i))
            cout << i + 1 << ' ';
    cout << '\n';
    return 0;
}