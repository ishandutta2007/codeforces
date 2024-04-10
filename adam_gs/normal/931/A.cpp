#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    a=abs(a-b);
    int w=0;
    for (int i = 1; a>0; ++i) {
        w+=i;
        --a;
        if (a>0) {
            w+=i;
            --a;
        }
    }
    cout << w;
}