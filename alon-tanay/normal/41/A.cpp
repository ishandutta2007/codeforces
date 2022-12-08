#include <iostream>
#include <string>

using namespace std;

int main() {
    string ber;
    string bir;
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> ber;
    cin >> bir;
    int len = ber.length();
    for(int i = 0; i < len; i ++) {
        if(ber[i] != bir[len-i-1]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}