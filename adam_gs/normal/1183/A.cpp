#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    cin >> a;
    while (true) {
        int p = a, s=0;
        while (p>0) {
            s+=p%10;
            p/=10;
        }
        if (s%4==0){cout<<a;return 0;}
        ++a;
    }
}