#include<bits/stdc++.h>
using namespace std;
int main(){
    int mod=998244353;
    int n;
    cin>>n;
    vector<int> ans;
    ans.push_back(10);
    long long a=1, b=10;
    for(int i=1; i<n; i++){
        ans.push_back((b*18+(i-1)*a*81)%mod);
        a*=10;
        a%=mod;
        b*=10;
        b%=mod;
    }
    reverse(ans.begin(), ans.end());
    for(int i:ans){
        cout<<i<<" ";
    }
}