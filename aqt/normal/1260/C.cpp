#include <bits/stdc++.h>

using namespace std;

int main(){
    long long T;
    cin >> T;
    while(T--){
        long long A, B, K;
        cin >> A >> B >> K;
        long long G = __gcd(A, B);
        long long L = A*B/G;
        if(B <= A){
            swap(A, B);
        }
        if((B-G)/A+!!((B-G)%A) >= K){
            cout << "REBEL" << endl;
        }
        else{
            cout << "OBEY" << endl;
        }
    }
}