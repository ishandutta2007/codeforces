#include <bits/stdc++.h>

using namespace std;

long long N, K;

long long totient(long long n){
    long long t = n;
    for(long long i = 2; i<=sqrt(n); i++){
        if(t%i == 0){
            while(t%i == 0){
                t /= i;
            }
            n /= i;
            n *= (i-1);
        }
    }
    if(t > 1){
        n /= t;
        n *= (t-1);
    }
    return n;
}

int main(){
    cin >> N >> K;
    for(long long i = 1; i<=K && N > 1; i+=2){
        N = totient(N);
    }
    cout << N%(1000000007) << endl;
}