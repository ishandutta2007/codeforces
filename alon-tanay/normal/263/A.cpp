#include <iostream>

using namespace std;

int main() {
    int a;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i = 0; i < 5; i ++) {
        for(int j = 0; j < 5; j ++) {
            cin >> a;
            if(a) {
                cout << abs(j-2) + abs(i-2);
            }
        }
    }
    return 0;
}