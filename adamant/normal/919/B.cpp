#include <bits/stdc++.h>

using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    for(int i = 1; ; i++) {
        int t = i;
        int sum = 0;
        while(t) {
            sum += t % 10;
            t /= 10;
        }
        if(sum == 10) {
            k--;
        }
        if(k == 0) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}