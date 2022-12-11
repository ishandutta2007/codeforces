#include <bits/stdc++.h>

using namespace std;

long long N;

int main(){
    cin >> N;
    if(N == 1){
        cout << 1 << endl;
        return 0;
    }
    long long cnt = 0, p = 0;
    for(long long i = 2; i<=sqrt(N); i++){
        if(N%i == 0){
            cnt++;
            p = i;
            while(N%i == 0){
                N /= i;
            }
        }
    }
    if(N > 1){
        cnt++;
    }
    if(!p){
        p = N;
    }
    if(cnt <= 1){
        cout << p << "\n";
    }
    else{
        cout << 1 << endl;
    }
}