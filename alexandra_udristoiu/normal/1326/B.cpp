#include<iostream>
using namespace std;
int n, i, a, b, x;
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> b;
        a = b + x;
        cout<< a <<" ";
        x = max(x, a);
    }
}