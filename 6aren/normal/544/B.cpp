#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    if (k>n*n-(n*n)/2) return cout << "NO", 0;
    cout << "YES" << endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (!k){
                cout << "S";
                continue;
            }
            if ((i+j)%2) cout << "S";
            else {
                cout << "L";
                k--;
            }
        }
        cout << endl;
    }
    return 0;
}