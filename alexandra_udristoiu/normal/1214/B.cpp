#include<iostream>
using namespace std;
int a, b, n, i, nr;
int main(){
    cin>> a >> b >> n;
    for(i = 0; i <= min(n, a); i++){
        if(n - i <= b){
            nr++;
        }
    }
    cout<< nr;
}