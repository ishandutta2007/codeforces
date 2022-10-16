#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int s = 0;
    while(s < (int)a.length() && a[s] == '0')
        s++;
    a = a.substr(s);
    s = 0;
    while(s < (int)b.length() && b[s] == '0')
        s++;
    b = b.substr(s);
    if(a.length() != b.length()) {
        if(a.length() > b.length())
            cout << '>' << '\n';
        else
            cout << '<' << '\n';
        return 0;
    }
    for(size_t i = 0; i < a.length(); i++)
        if(a[i] != b[i]) {
            if(a[i] > b[i])
                cout << '>' << '\n';
            else
                cout << '<' << '\n';
            return 0;
        }
    cout << '=' << '\n';
    return 0;
}