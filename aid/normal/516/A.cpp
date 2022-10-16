#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int seven = 0, five = 0, three = 0, two = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        int a = c - '0';
        seven += a / 7;
        five += a / 5;
        three += a / 3 + a / 9;
        two += a / 2 + a / 4 + a / 8;
    }
    while(seven) {
        cout << 7;
        seven--;
        five--;
        three -= 2;
        two -= 4;
    }
    while(five) {
        cout << 5;
        five--;
        three--;
        two -= 3;
    }
    while(three) {
        cout << 3;
        three--;
        two--;
    }
    while(two) {
        cout << 2;
        two--;
    }
    cout << '\n';
    return 0;
}