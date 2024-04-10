#include <iostream>

using namespace std;

int main() {
    int n; 
    int x = 0;
    char input[3];
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i ++) {
        cin >> input;
        x += ((input[1] == '+') ? 1 : -1);
    }
    cout << x;
    return 0;
}