#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, a2, a3, b, b2, b3, n;
    cin >> a >> a2 >> a3 >> b >> b2 >> b3 >> n;
    a+=a2+a3+4;
    b+=b2+b3+9;
    a/=5;
    b/=10;
    if (a+b<=n){
        cout << "YES";
    } else {
        cout << "NO";
    }
}