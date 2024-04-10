#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    while(n--){
        int x, y;
        cin >> x >> y;
        if(b <= x+y && x+y <= 2*a-b && -b <= x-y && x-y <= b){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}