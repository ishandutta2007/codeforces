#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
string bus[N];

int main (int argc, char const *argv[]) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> bus[i];

    for (int i = 1; i <= n; ++i) {
        if (bus[i][0] == bus[i][1] and bus[i][0] == 'O') {
            bus[i][0] = bus[i][1] = '+';
            cout << "YES\n";
            for (int i = 1; i <= n; ++i) cout << bus[i] << '\n';
            return 0;
        } else if (bus[i][3] == bus[i][4] and bus[i][3] == 'O') {
            bus[i][3] = bus[i][4] = '+';
            cout << "YES\n";
            for (int i = 1; i <= n; ++i) cout << bus[i] << '\n';
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}