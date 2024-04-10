#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t --) {
        long long n;
        cin >> n;
        vector<int> zeros(n+1);
        int zer = 0;
        for(int i = 0; i < n; i ++) {
            zeros[i] = zer;
            int x;
            cin >> x;
            if(x == 0) {
                zer ++;
            }
        }
        zeros[n] = zer;
        long long res = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = i; j < n; j ++) {
                res += j - i + 1;
                res += zeros[j+1] - zeros[i];
            }
        }
        cout << res << "\n";
    }

    return 0;
}