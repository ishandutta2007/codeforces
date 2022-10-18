#include <bits/stdc++.h>

using namespace std;

#define int long long
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    if (n % 2 == 0){
        cout << n / 2 << endl;
        return 0;
    }
    for (int i = 3; i <= sqrt(n); ++i){
        if (n % i == 0){
            cout << 1 + (n - i) / 2 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}