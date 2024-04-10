#include <bits/stdc++.h>
using namespace std;

int q,l,r;

int sum(int n){
    if (n%2==0) return n/2;
    else return n/2-n;
}

int main(){
    cin >> q;
    while (q--){
        cin >> l >> r;
        cout << sum(r)-sum(l-1) << endl;
    }
}