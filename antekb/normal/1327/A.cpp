#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long k;
        cin>>n>>k;
        if(n>=k*k and (n&1)==(k&1)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}