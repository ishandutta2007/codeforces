#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    int lucky_digits = 0;
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> input;
    int len = input.length();
    for(int i = 0; i < len; i ++) {
        if(input[i] == '4' || input[i] == '7') {
            lucky_digits ++;
        }
    }
    if(lucky_digits == 4 || lucky_digits == 7) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}