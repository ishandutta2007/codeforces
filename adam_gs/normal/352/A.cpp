#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a=0, b=0;
    while(n--) {
        int x;
        cin >> x;
        if(x==0) ++a; else ++b;
    }
    b/=9; b*=9;
    if(!b && a) {
        cout << 0 << '\n';
        return 0;
    }
    if(!b || !a) {
        cout << -1 << '\n';
        return 0;
    }
    while(b--) cout << 5;
    while(a--) cout << 0;
    cout << '\n';
}