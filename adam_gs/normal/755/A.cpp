#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m=1;
    cin >> n;
    while (true) {
        bool t = true;
        for (int i = 2; i*i<=n*m+1; ++i) {
            if ((n*m+1)%i==0) t=false;
        }
        if (t==false) {
            cout << m;
            return 0;
        }
        ++m;
    }
}