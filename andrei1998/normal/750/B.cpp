#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int h = 0;

    while (n --) {
        int val;
        cin >> val;

        string str;
        cin >> str;

        if (str == "East" || str == "West") {
            if (h == 0 || h == 20000) {
                cout << "NO\n";
                return 0;
            }
        }
        else if (str == "South") {
            h += val;
            if (h > 20000) {
                cout << "NO\n";
                return 0;
            }
        }
        else {
            h -= val;
            if (h < 0) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    if (h != 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    return 0;
}