#include <iostream>
#include <string>

using namespace std;

const int P = 15, PR[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int cnt = 0, p = -1;;
    for(int i = 0; i < P; i++) {
        cout << PR[i] << endl;
        string s;
        cin >> s;
        if(s[0] == 'y') {
            cnt++;
            p = PR[i];
        }
    }
    if(cnt > 1)
        cout << "composite\n";
    else {
        if(p != -1 && p * p <= 100) {
            cout << p * p << endl;
            string s;
            cin >> s;
            if(s[0] == 'y')
                cout << "composite\n";
            else
                cout << "prime\n";
        }
        else
            cout << "prime\n";
    }
    return 0;
}