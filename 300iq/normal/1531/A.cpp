#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string color = "blue";
    bool blocked = false;
    while (n--) {
        string s;
        cin >> s;
        if (s == "lock") blocked = true;
        else if (s == "unlock") blocked = false;
        else {
            if (!blocked) {
                color = s;
            }
        }
    }
    cout << color << endl;
}