#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n%10>=5) {
        n/=10;
        n+=1;
        n*=10;
    } else {
        n/=10;
        n*=10;
    }
    cout << n;
}