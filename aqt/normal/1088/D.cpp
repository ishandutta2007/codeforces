#include <bits/stdc++.h>

using namespace std;

int query(int x, int y){
    cout << "? " << x << " " << y << endl;
    cout.flush();
    int n;
    cin >> n;
    return n;
}

int main(){
    int c = query(0, 0);
    int a = 0, b = 0;
    for(int i = 29; i>=0; i--){
        int x = query(a^(1<<i), b), y = query(a, b^(1<<i));
        if(x == y){
            if(c == 1){
                a ^= (1<<i);
            }
            else{
                b ^= (1<<i);
            }
            c = x;
        }
        else if(x == -1){
            a ^= (1<<i), b ^= (1<<i);
        }
    }
    cout << "! " << a << " " << b << endl;
}