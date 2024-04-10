#include<iostream>
using namespace std;
int a, b, c, x;
int main(){
    cin>> a >> b >> c;
    x = min(a, min(b - 1, c - 2) );
    cout<< 3 * x + 3;
}