#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    bool first = true;
    int occur[3] = {0,0,0};
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> input;
    int len = input.length();

    for(int i = 0; i < len; i += 2) {
        occur[input[i]-49] ++;
    }
    while((occur[0]--) > 0) {
        if(!first) {
            cout << "+";
        }
        cout << "1";
        first = false;
    }
    while((occur[1]--) > 0) {
        if(!first) {
            cout << "+";
        }
        cout << "2";
        first = false;
    }
    while((occur[2]--) > 0) {
        if(!first) {
            cout << "+";
        }
        cout << "3";
        first = false;
    }
    return 0;
}