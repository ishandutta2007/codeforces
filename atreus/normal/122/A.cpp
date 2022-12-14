#include <bits/stdc++.h>

using namespace std;

bool islucky(int n){
    int k;
    while (n > 0){
        k = n % 10;
        if (k != 4 && k != 7)
            return 0;
        n /= 10;
    }
    return 1;
}

int main (){
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++){
        if (n % i == 0 && islucky(i) == true)
            return cout << "YES", 0;
    }
    cout << "NO" << endl;
}