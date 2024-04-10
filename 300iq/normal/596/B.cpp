#include <bits/stdc++.h>
using namespace std;


int main(){
    long long n;
    cin >> n;
    long long a[n];
    long long counter = 0;
    a[0] = 0;
    for(long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
//    int counter = 0;
    for(long long i = 1; i <= n; i++) {
        counter += abs(a[i] - a[i - 1]);
    }
    cout << counter;
}