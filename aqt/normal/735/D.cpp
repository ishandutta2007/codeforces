#include <bits/stdc++.h>

using namespace std;

int N;

bool isPrime(int n){
    for(int i = 2; i<=sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    if(isPrime(N)){
        cout << 1 << endl;
        return 0;
    }
    else if(N%2 == 0){
        cout << 2 << endl;
        return 0;
    }
    else if(isPrime(N-2)){
        cout << 2 << endl;
    }
    else{
        cout << 3 << endl;
    }
}