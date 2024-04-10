#include<iostream>
using namespace std;
int n, nr1, nr2, p, u, x, i;
int s1[46000], s2[46000];
int main(){
    cin>> n;
    if(n <= 2){
        cout<<"No";
        return 0;
    }
    cout<<"Yes\n";
    if(n % 2 == 1){
        p = 1;
        u = n;
    }
    else{
        p = 1;
        u = n - 1;
        s1[++nr1] = n;
    }
    while(p < u){
        if(x == 0){
            s2[++nr2] = p;
            s2[++nr2] = u;
        }
        else{
            s1[++nr1] = p;
            s1[++nr1] = u;
        }
       // x = (x + 1) % 2;
        p++;
        u--;
    }
    s1[++nr1] = p;
    cout<< nr1 <<" ";
    for(i = 1; i <= nr1; i++){
        cout<< s1[i] <<" ";
    }
    cout<<"\n";
    cout<< nr2 <<" ";
    for(i = 1; i <= nr2; i++){
        cout<< s2[i] <<" ";
    }
}