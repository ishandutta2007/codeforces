#include<iostream>
using namespace std;
int n, a, b, c;
int main(){
    cin>> a >> b >> c >> n;
    if(c > min(a, b) || n <= a + b - c){
        cout<< -1;
    }
    else{
        cout<< n - (a + b - c);
    }
}