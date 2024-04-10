#include <bits/stdc++.h>
using namespace std;
int t,n,x,a,b;
int main(){
    cin>>t;while (t--){
    cin>>n>>x>>a>>b;cout<<min(n-1,abs(a-b)+x)<<endl;}
}