#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        if(i%4 < 2) {
            cout << "a";
        }
        else {
            cout << "b";
        }
    }
}