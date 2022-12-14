#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int s1 = 0, f1 = 0;
    for (int i = 0; i < n - 1; i++){
        if (s[i] == 'S' && s[i + 1] == 'F')
            s1 ++;
        if (s[i] == 'F' && s[i + 1] == 'S')
            f1 ++;
    }
    if (s1 > f1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}