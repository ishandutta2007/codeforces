#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        if(k%3 == 0){
            n %= (k+1);
            if(n%3 == 0 && n != k){
                cout << "Bob" << "\n";
            }
            else{
                cout << "Alice" << "\n";
            }
        }
        else{
            if(n%3){
                cout << "Alice" << "\n";
            }
            else{
                cout << "Bob" << "\n";
            }
        }
    }
}