#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string lol1, lol2;
    map<string, int> wk = {
        {"monday", 0},
        {"tuesday", 1},
        {"wednesday", 2},
        {"thursday", 3},
        {"friday", 4},
        {"saturday", 5},
        {"sunday", 6},
    };
    cin >> lol1 >> lol2;
    int ll1 = wk[lol1], ll2 = wk[lol2];
    if((ll1 + 30) % 7 == ll2)
        cout << "YES\n";
    else if((ll1 + 31) % 7 == ll2)
        cout << "YES\n";
    else if((ll1 + 28) % 7 == ll2)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}