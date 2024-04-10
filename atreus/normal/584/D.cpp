#include <bits/stdc++.h>

using namespace std;

string s[300];

bool prime(int n){
    if (n == 0 || n == 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    if (prime(n)){
        cout << 1 << endl << n;
        return 0;
    }
    if (prime(n - 2)){
        cout << 2 << endl << 2 << " " << n - 2;
        return 0;
    }
    for (int i = n - 3; i >= n / 2; i--){
        if (prime(i) && prime(n - i - 3)){
            cout << 3 << endl << 3 << " " << i << " " << n - i - 3 << endl;
            return 0;
        }
    }
}