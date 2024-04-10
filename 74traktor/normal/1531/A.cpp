#include<bits/stdc++.h>

using namespace std;

main() {
    int n;
    cin >> n;
    int flag = 1;
    string color = "blue";
    for (int i = 1; i <= n; ++i) {
        string type;
        cin >> type;
        if (type == "lock") flag = 0;
        else if (type == "unlock") flag = 1;
        else if (flag) color = type;
    }
    cout << color << '\n';
}