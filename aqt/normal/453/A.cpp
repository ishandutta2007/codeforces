#include <bits/stdc++.h>

using namespace std;

double N, M;

double fpow(double b, int e){
    if(e == 0){
        return 1;
    }
    double res = fpow(b, e/2);
    res *= res;
    if(e%2){
        res *= b;
    }
    return res;
}

int main(){
    double tot = 0;
    cin >> M >> N;
    for(double i = 1; i<=M; i++){
        tot += i*(fpow(i/M, (int) N)-fpow((i-1)/M, (int) N));
    }
    cout << tot << endl;
}