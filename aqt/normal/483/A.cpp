#include <bits/stdc++.h>

using namespace std;

int main(){
    long long l, r;
    cin >> l >> r;
    for(long long a = l; a<=r; a++){
        for(long long b = a+1; b<=r; b++){
            for(long long c = b+1; c<=r; c++){
                if(__gcd(a, b) == 1 && __gcd(b, c) == 1 && __gcd(a, c) != 1){
                    cout << a << " " << b << " " << c << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
}