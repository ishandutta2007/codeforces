#include <bits/stdc++.h>

using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int m = n;
    int n2 = 0, n5 = 0;
    while (n % 5 == 0){
        n /= 5;
        n5 ++;
    }
    while (n % 2 == 0){
        n /= 2;
        n2 ++;
    }
    long long tot = 1;
    while (n2 < k){
        tot *= 2;
        n2 ++;
    }
    while (n5 < k){
        tot *= 5;
        n5 ++;
    }
    cout << tot * m << endl;
}