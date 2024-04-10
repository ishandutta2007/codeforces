#include<iostream>
using namespace std;
int t;
long long a, b, n, m;
int main(){
    cin>> t;
    for(; t; t--){
        cin>> a >> b >> n >> m;
        if(a + b < n + m || min(a, b) < m){
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
        }
    }
}