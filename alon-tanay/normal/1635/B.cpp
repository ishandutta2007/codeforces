#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> xs(n);
        for(int &x : xs) {
            cin >> x;
        }
        int total = 0;
        for(int i = 1; i < n - 1; i ++) {
            if((xs[i] > xs[i-1]) && (xs[i] > xs[i+1])) {
                total ++;
                if(i < n - 2) {
                    xs[i+1] = max(xs[i],xs[i+2]);
                } else {
                    xs[i+1] = xs[i];
                }
            }
        }
        cout << total << "\n";
        for(int x : xs) {
            cout << x << " ";
        }
        cout << "\n";

    }

    return 0;
}