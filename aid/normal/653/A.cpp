#include <iostream>

using namespace std;

const int MAXX = 1005;
char c[MAXX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        c[t] = true;
    }
    for(int i = 0; i + 2 < MAXX; i++)
        if(c[i] && c[i + 1] && c[i + 2]) {
            cout << "YES\n";
            return 0;
        }
    cout << "NO\n";
    return 0;
}