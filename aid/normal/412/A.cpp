#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    string s;
    cin >> n >> k >> s;
    k--;
    if(k < n - k - 1) {
        for(int i = k; i > 0; i--)
            cout << "LEFT\n";
        for(int i = 0; i < n - 1; i++)
            cout << "PRINT " << s[i] << '\n' << "RIGHT\n";
        cout << "PRINT " << s[n - 1] << '\n';
    }
    else {
        for(int i = k; i < n - 1; i++)
            cout << "RIGHT\n";
        for(int i = n - 1; i > 0; i--)
            cout << "PRINT " << s[i] << '\n' << "LEFT\n";
        cout << "PRINT " << s[0] << '\n';
    }
    return 0;
}