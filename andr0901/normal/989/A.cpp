#include <iostream>
#include <set>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s.size() < 3) {
        cout << "No";
        return 0;
    }
    for (int i = 2; i < s.size(); i++) {
        set <int> a;
        if (s[i] != '.') a.insert (s[i]);
        if (s[i - 1] != '.') a.insert (s[i - 1]);
        if (s[i - 2] != '.') a.insert (s[i - 2]);
        if (a.size() == 3) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}