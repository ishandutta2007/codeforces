#include <bits/stdc++.h>

using namespace std;

bool srt(int a, int b) {
    return b<a;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        int ma=0;
        int mb=0;
        while (a--) {
            int p;
            cin >> p;
            ma=max(ma, p);
        }
        while (b--) {
            int p;
            cin >> p;
            mb=max(mb, p);
        }
        if (ma > mb) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << '\n';
    }
}