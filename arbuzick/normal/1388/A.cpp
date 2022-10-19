#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n <= 30){
            cout << "NO\n";
            continue;
        }
        if(n-30 != 6 && n-30 != 10 && n-30 != 14){
            cout << "YES\n";
            cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << n-30 << '\n';
            continue;
        }
        cout << "YES\n";
        cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << n-31 << '\n';
    }
    return 0;
}