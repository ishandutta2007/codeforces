#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    if(n > m){
        swap(n, m);
    }
    if(n == 1){
        cout << m/6*6 + 2*max(0, m%6-3);
    }
    else if(n == 2 && m == 2){
        cout << 0 << endl;
    }
    else if(n == 2 && m == 3){
        cout << 4 << endl;
    }
    else if(n == 2 && m == 7){
        cout << 12 << endl;
    }
    else{
        cout << 1LL*n*m/2*2 << endl;
    }
}