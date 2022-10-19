#include<bits/stdc++.h>
using namespace std;
int main(){
    long long u, v;
    cin>>u>>v;
    if(u==v and u==0){
        cout<<"0";
        return 0;
    }
    if(v-u<0 or (v-u)%2==1){
        cout<<"-1";
        return 0;
    }
    if(v==u){
        cout<<"1\n"<<u;
        return 0;
    }
    long long k=(v-u)/2;
    if((u^k)==(u+k)){
        cout<<"2\n"<<(u^k)<<" "<<k;
        return 0;
    }
    cout<<"3\n"<<u<<" "<<k<<" "<<k;
}