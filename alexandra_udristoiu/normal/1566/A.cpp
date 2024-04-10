#include<iostream>
using namespace std;
int t, n, s, nr, x;
int main(){
    cin>> t;
    for (; t; t--) {
        cin>> n >> s;
        nr = n / 2 + 1;
        cout<< s / nr <<"\n";
    }
}