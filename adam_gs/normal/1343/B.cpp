#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n%4==0) {
            cout << "YES\n";
            int s = 0;
            for (int i = 0; i < n/2; ++i) {
                cout << 2*(i+1) << " ";
                s+=2*(i+1);
            }
            int s2=0;
            for (int i = 0; i < n/2-1; ++i) {
                cout << 2*i+1 << " ";
                s2+=2*i+1;
            }
            cout << s-s2;
        } else {
            cout << "NO";
        }
        cout << '\n';
    }
}