#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int main(){
    int n, k;
    cin>>n>>k;
    int ile=1, licznik=0;
    long long ans=1, ans2=0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x+k>n){
            ans2+=x;
            if(licznik++){
                ans*=ile;
                ans%=mod;
            }
            ile=1;
        }
        else{
            ile++;
        }
    }
    cout<<ans2<<" "<<ans;
}