#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e9;

int main(){
    ios_base::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= maxn; i++){
        if (i % 2 == 1){
            a -= i;
            if (a < 0){
                cout << "Vladik" << endl;
                return 0;
            }
        }
        else {
            b -= i;
            if (b < 0){
                cout << "Valera" << endl;
                return 0;
            }
        }
    }
}