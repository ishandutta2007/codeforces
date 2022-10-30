#include<iostream>
#include<algorithm>
using namespace std;
int n, i, sum, v[55], t;
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        sum = 0;
        for(i = 1; i <= n; i++){
            cin>> v[i];
            sum += v[i];
        }
        sort(v + 1, v + n + 1);
        if(sum == 0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            if(sum > 0){
                for(i = n; i >= 1; i--){
                    cout<< v[i] <<" ";
                }
            }
            else{
                for(i = 1; i <= n; i++){
                    cout<< v[i] <<" ";
                }
            }
            cout<<"\n";
        }
    }
}