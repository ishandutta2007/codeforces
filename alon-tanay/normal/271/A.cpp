#include <iostream>

using namespace std;

bool bad(int n) {
    bool occur[10] = {false,false,false,false,false,false,false,false,false,false};
    for(int i = 0; i < 3; i ++) {
        occur[n%10] = true;
        n /= 10;
        if(occur[n%10]) {
            return true;
        }
    }
    return false;
}

int main() {
    int y;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> y;
    y ++;
    while(bad(y)) {y++;}
    cout << y;
    return 0;
}