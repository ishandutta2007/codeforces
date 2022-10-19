#include <bits/stdc++.h>

using namespace std;

int main() {
    long long l, r;
    cin >> l >> r;
    while (true) {
        long long p=l;
        bool t = true;
        long long cyfr[11];
        for (int i = 0; i <= 10; ++i){
            cyfr[i]=0;
        }
        while (p>0) {
            long long pom=p%10;
            if (cyfr[pom]==1) {
                t=false;
            } else {
                cyfr[pom]=1;
            }
            p/=10;
        }
        if (t==true) {
            break;
        }
        ++l;
    }
    if (l<=r) {
        cout << l;
    } else {
        cout << -1;
    }
}