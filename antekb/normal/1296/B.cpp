#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        cout<<n+(n-1)/9<<"\n";
    }
}