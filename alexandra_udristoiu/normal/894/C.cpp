#include<iostream>
using namespace std;
int n, i, x;
int v[2005];
int cmmdc(int a, int b){
    int r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    x = v[1];
    for(i = 2; i <= n; i++){
        x = cmmdc(x, v[i]);
    }
    if(x != v[1]){
        cout<< -1;
        return 0;
    }
    cout<< 2 * n - 1 <<"\n"<< v[1] <<" ";
    for(i = 2; i <= n; i++){
        cout<< v[i] <<" "<< v[1] <<" ";
    }
    return 0;
}