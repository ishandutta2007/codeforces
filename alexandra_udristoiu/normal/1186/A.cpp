#include<iostream>
using namespace std;
int n, m, k;
int main(){
    cin>> n >> m >> k;
    if(n <= m && n <= k){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}