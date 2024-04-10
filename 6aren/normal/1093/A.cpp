#include <bits/stdc++.h>
using namespace std;

int main(){
    int ntest;
    cin >> ntest;
    while (ntest--){
        int x;
        cin >> x;
        if (x%7==0) cout << x/7 << endl;
        else if (x&7==1) cout << (x-8)/7+2 << endl;
        else cout << x/7+1 << endl;
    }
}