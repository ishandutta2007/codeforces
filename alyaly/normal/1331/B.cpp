#include<bits/stdc++.h>
using namespace std;int n;
int main(){
    cin>>n;
    for(int i=2;i<=n;i++)if(n%i==0){cout<<i<<n/i<<endl;return 0;}
    return 0;
}