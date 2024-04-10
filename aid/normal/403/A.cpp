#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++) {
        int n, p;
        cin >> n >> p;
        p += 2 * n;
        for(int i = 1; i < n && p > 0; i++)
            for(int j = 0; j < n && p > 0; j++, p--)
                cout << j + 1 << ' ' << (j + i) % n + 1 << '\n';
    }
    return 0;
}