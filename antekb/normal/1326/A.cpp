#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<"-1\n";
        }
        else{
            if(n%9==1){
                cout<<"4";
            }
            else{
                cout<<"2";
            }
            for(int i=2; i<n; i++){
                cout<<"2";
            }
            cout<<"9\n";
        }
    }
}