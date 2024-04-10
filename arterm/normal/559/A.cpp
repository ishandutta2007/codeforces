#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);

    int a[6];
    for (int i = 0; i < 6; ++i) 
        cin >> a[i];

    int s = a[0] + a[1] + a[2];

    int ans = s * s - a[0] * a[0] - a[2] * a[2] - a[4] * a[4];

    cout << ans << endl; 

    return 0;
}