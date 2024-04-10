#include <bits/stdc++.h>

using namespace std;

#define int long long

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while (cin >> s){
        if (s == "end") return 0;
        cout << "? " << 0 << " " << 1 << endl;
        char ans;
        cin >> ans;
        if (ans == 'x'){
            cout << "! " << 1 << endl;
            continue;
        }
        int l = 1, r = 2;
        while (1){
            cout << "? " << l << " " << r << endl;
            char ans;
            cin >> ans;
            if (ans == 'x') break;
            l *= 2;
            r *= 2;
        }
        while (r - l > 1){
            int m = (r + l) / 2;
            cout << "? " << l << " " << m << endl;
            char t;
            cin >> t;
            if (t == 'x') r = m;
            else l = m;
        }
        cout << "! " << r << endl;
    }
}