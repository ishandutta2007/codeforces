#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    while (true) {
        ++a;
        bool t=true;
        for (int i = 2; i*i<=a; ++i){
            if (a%i==0) {
                t=false;
            }
        }
        if (t==true) break;
    }

    if (a==b) {
        cout << "YES";
    } else {
    cout << "NO";
        }
}