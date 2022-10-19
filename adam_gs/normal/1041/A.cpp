#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int mi=1100000000;
    int ma=-1;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        mi=min(mi, a);
        ma=max(ma, a);
    }
    cout << ma-mi-n+1;
}