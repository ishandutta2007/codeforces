#include <bits/stdc++.h>

using namespace std;

void f(int n){
    cout << n << " ";
}

int main(){
    cout.tie(0);
    int N;
    cin >> N;
    int even = N, odd = N;
    if(N%2 == 1){
        even--;
        odd -= 2;
        for(int n = 2; n<=even; f(n), n+=2);
        for(int n = even; n>0; f(n), n-=2);
        for(int n = 1; n<=odd; f(n), n+=2);
        f(N);
        for(int n = odd; n>0; f(n), n-=2);
        f(N);
    }
    else{
        odd--;
        even -= 2;
        for(int n = 1; n<=odd; f(n), n+=2);
        for(int n = odd; n>0; f(n), n-=2);
        for(int n = 2; n<=even; f(n), n+=2);
        f(N);
        for(int n = even; n>0; f(n), n-=2);
        f(N);
    }
}