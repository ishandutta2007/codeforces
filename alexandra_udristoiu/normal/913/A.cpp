#include<iostream>
using namespace std;
int n, m;
int main(){
    cin>> n >> m;
    if(n > 30){
        cout<< m;
    }
    else{
        cout<< m % (1 << n);
    }
}