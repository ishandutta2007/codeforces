#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    long int a, b, c;

    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> t;
    for(int i = 0; i < t; i ++) {
        cin >> a >> b >> c;
        if(c < a) {
            cout << "-1 1" << endl;
            continue;
        }
        if(c/b >= a) {
            cout << "1 -1" << endl;
            continue;
        }
        cout << (c == a ? "-1 " : "1 ") << b << endl;
    }
    return 0;
}