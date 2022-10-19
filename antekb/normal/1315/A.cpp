#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        int a, b, x, y;
        cin>>a>>b>>x>>y;
        cout<<max(max(x, a-x-1)*b, max(y, b-y-1)*a)<<"\n";
    }
}