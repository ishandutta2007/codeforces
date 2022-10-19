#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x = n;
        int k = 0;
        while(x%6 == 0){
            x /= 6;
            k++;
        }
        while(x%3 == 0){
            x /= 3;
            k += 2;
        }
        if(x != 1)
            cout << -1 << "\n";
        else
            cout << k << "\n";
    }
    return 0;
}