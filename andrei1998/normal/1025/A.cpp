#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "Yes\n";
        return 0;
    }

    string str;
    cin >> str;

    map <char, int> mp;
    for (auto it: str)
        ++ mp[it];

    bool have = false;
    for (auto it: mp)
        if (it.second > 1)
            have = true;

    if (!have) {
        cout << "No\n";
        return 0;
    }
    else {
        cout << "Yes\n";
    }
    return 0;
}