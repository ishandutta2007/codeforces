#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int a, b, k;
        cin >> a >> b >> k;
        if(k%3 == 2){
            cout << (a^b) << "\n";
        }
        else if(k%3 == 0){
            cout << a << "\n";
        }
        else{
            cout << b << "\n";
        }
    }
}