#include<iostream>
using namespace std;
int i, k, a, b, x, y;
int main(){
    cin>> a >> b >> x >> y >> k;
    for(i = x; i <= y; i++){
        if(i * 1LL * k >= a && i * 1LL * k <= b){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}