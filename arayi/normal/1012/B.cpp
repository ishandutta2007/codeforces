#include<bits/stdc++.h>
using namespace std;
int f[1<<19],n,m,q,t,x,y;
int g(int x){return f[x]?f[x]=g(f[x]):x;}
int main(){
    cin>>n>>m>>q;
    while(q--){
        cin>>x>>y;
        x=g(x);y=g(y+n);
        if(x-y)f[x]=y,--m;
    }cout<<n+m-1;
}