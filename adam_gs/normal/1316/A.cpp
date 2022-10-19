#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int p;
        cin >> p;
        int s=0;
        while (--n) {
            int a;
            cin >> a;
            s+=a;
        }
        cout << p+min(m-p, s) << '\n';
    }
}