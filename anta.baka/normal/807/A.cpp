#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool A = true, B = true;
    int last;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        A &= (a == b);
        if(i) {
            B &= (last >= a);
        }
        last = a;
    }
    if(!A) {
        cout << "rated";
    } else if(B) {
        cout << "maybe";
    } else {
        cout << "unrated";
    }
}