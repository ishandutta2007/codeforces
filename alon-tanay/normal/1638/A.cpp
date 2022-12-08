#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> ps(n);
        int idx = n + 1;
        for(int i = 1; i <= n; i++) {
            int p;
            cin >> p;
            ps[i-1] = p;
            if(p != i) {
                for(int j = i + 1; j <= n; j ++) {
                    int x;
                    cin >> x;
                    ps[j-1] = x;
                    if(x == i) {
                        int l = i - 1;
                        int r = j - 1;
                        while(l < r) {
                            int tmp = ps[l];
                            ps[l] = ps[r];
                            ps[r] = tmp;
                            l ++;
                            r --;
                        }
                    }
                }
                break;
            }
        }
        for(int x : ps) {
            cout << x << " ";
        }
        cout << "\n";
        
    }

    return 0;
}