#include<iostream>
using namespace std;
int a, b, n, x, y, t;
int main(){
    cin>> t;
    for(; t; t--){
        cin>> a >> b >> n;
        x = 0;
        while(a <= n && b <= n){
            x++;
            if(a < b){
                a += b;
            }
            else{
                b += a;
            }
        }
        cout<< x <<"\n";
    }
}