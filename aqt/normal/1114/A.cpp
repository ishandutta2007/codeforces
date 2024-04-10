#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, y, z;
    int a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    if(x <= a){
        a -= x;
    }
    else{
        cout << "NO" << endl;
        return 0;
    }
    if(a+b >= y){
        a -= y;
    }
    else{
        cout << "NO" << endl;
        return 0;
    }
    if(a+b+c >= z){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}