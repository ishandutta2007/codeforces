#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    if (x ==1 ) {
        cout << -1;
        return 0;
    }
    if (x<=3) {
        cout << x  << " " << x;
        return 0;
    }
    cout << x-x%2 << " " << (x-x%2) /2;
}