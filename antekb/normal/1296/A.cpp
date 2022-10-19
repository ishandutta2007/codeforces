#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        int n, x;
        cin>>n;
        int p=0, np=0;
        for(int i=0; i<n; i++){
            cin>>x;
            if(x%2){
                np++;
            }
            else{
                p++;
            }
        }
        if(p and np){
            cout<<"YES\n";
        }
        else{
            if(np%2){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
}