#include<bits/stdc++.h>

using namespace std;

int main (){
    int n, r;
    cin >> n >> r;
    for (int i = 1; i <= 10; i++){
        int m = n * i;
        if (m % 10 == 0 || m % 10 == r)
            return cout << i << endl, 0;
    }
}