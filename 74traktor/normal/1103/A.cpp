#include <bits/stdc++.h>

using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int t1 = 0, t2 = 0;
    for (auto c : s){
        if (c == '0'){
            if (t1 == 0){
                cout << 3 << " " << 4 << endl;
                t1 = 1;
            }
            else{
                cout << 1 << " " << 4 << endl;
                t1 = 0;
            }
        }
        else{
            if (t2 == 0){
                cout << 1 << " " << 1 << endl;
                t2 = 1;
            }
            else{
                cout << 1 << " " << 3 << endl;
                t2 = 0;
            }
        }
    }
    return 0;
}