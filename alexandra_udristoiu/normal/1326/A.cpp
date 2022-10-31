#include<iostream>
using namespace std;
int t, n, i;
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        if(n == 1){
            cout<<"-1\n";
        }
        else{
            if( (n - 1) * 2 % 3 != 0){
                for(i = 1; i < n; i++){
                    cout<< 2;
                }
                cout<<"3\n";
            }
            else{
                for(i = 1; i < n - 1; i++){
                    cout<< 2;
                }
                cout<<"33\n";
            }
        }
    }
}