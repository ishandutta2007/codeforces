#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int ans = -1;
    vector <int> b;
    int l = n;
    while ( l > 0) {
        b.push_back(l % 10);
        l /= 10;
    }
    reverse(b.begin(), b.end());
    for ( int i = 1; i * i <= n; i++) {

        vector <int> a;
        int now = i * i;
        while ( now > 0) {
            a.push_back(now % 10);
            now /= 10;
        }
        reverse(a.begin(), a.end());

        int ans_now = 0;
        int k = a.size() - 1;
        for ( int j = b.size() - 1; j >= 0; j--) {
            if ( a[k] ==  b[j] && k >= 0) {
                k--;
            }
            else {
                ans_now++;
            }

        }

        if ( ans == -1 && k == -1) {

            ans = ans_now;

        }
        else if ( ans_now > -1 && k == -1){

            ans = min(ans, ans_now);
        }

    }

    cout << ans;
    return 0;

}