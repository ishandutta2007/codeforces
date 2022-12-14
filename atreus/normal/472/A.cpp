#include <bits/stdc++.h>

using namespace std;

bool notprime(int n){
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0)
            return true;
    }
    return false;
}

int main (){
    int n;
    cin >> n;
    int m = n / 2;
    if (n % 2 == 1)
        n = n / 2 + 1;
    else
        n = n / 2;
    for (int i = 0; i <= n / 2; i++){
        m += i;
        n -= i;
        if (notprime(n) == true && notprime(m) == true)
            return cout << n << " " << m, 0;
        n += i;
        m -= i;
    }
}