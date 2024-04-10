#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y){
    if(x == 0){
        return y;
    }
    else{
        return gcd(y % x, x);
    }
}

int main(){
    int a, m;
    cin >> a >> m;
    for(int i = 0; i < 20; i++){
        if(a % m == 0){
            cout << "Yes";
            return 0;
        }
        else{
            a += a % m;
        }
    }
    cout << "No";
}