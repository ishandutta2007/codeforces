#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n % 2 == 1){
        int a = n / 2;
        int b = n / 2 + 1;
        while (__gcd(a, b) != 1){
            a--;
            b++;
        }
        cout << a << " " << b;
    }
    else{
        int a = n / 2 - 1;
        int b = n / 2 + 1;
        while (__gcd(a, b) != 1){
            a --;
            b ++;
        }
        cout << a << " " << b;
    }
}