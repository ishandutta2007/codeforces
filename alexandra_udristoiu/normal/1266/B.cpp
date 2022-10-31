#include<iostream>
using namespace std;
int n, i;
long long x;
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> x;
        if(x % 14 >= 1 && x % 14 <= 6 && x > 14){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}