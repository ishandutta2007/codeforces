#include <bits/stdc++.h>

using namespace std;

long long a[1000];

int main() {
    long long n;
    cin >> n;
    long long ans = 1;
    a[0] = 1, a[1] = 1;
    for (int i = 2; i < 1000; i++){
        a[i] = a[i - 1] + a[i - 2];
        if (a[i] > n){
            cout << i - 2 << endl;
            return 0;
        }
    }
}